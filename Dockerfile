FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    gdb \
    clangd \
	clang-format \
    git \
    curl \
    ca-certificates \
    python3 \
    python3-pip \
    python3-venv \
    pipx \
    nodejs \
    npm \
    tmux \
    vim-gtk3 \
    && rm -rf /var/lib/apt/lists/*

RUN pipx install online-judge-tools --include-deps \
    && pipx inject online-judge-tools setuptools

ENV PATH="/root/.local/bin:${PATH}"

RUN npm install -g atcoder-cli

# Patch online-judge-tools for AtCoder KiB/MiB memory limit
RUN python3 - <<'PY'
from pathlib import Path

base = Path("/root/.local/share/pipx/venvs/online-judge-tools/lib")
files = list(base.glob("python*/site-packages/onlinejudge/service/atcoder.py"))

if not files:
    raise SystemExit("atcoder.py not found")

path = files[0]
s = path.read_text()

s = s.replace(
    r"(KB|MB)",
    r"(KB|MB|KiB|MiB)"
)

s = s.replace(
    "if memory_limit_unit == 'KB':",
    "if memory_limit_unit in ('KB', 'KiB'):"
)

s = s.replace(
    "elif memory_limit_unit == 'MB':",
    "elif memory_limit_unit in ('MB', 'MiB'):"
)

path.write_text(s)
print("patched:", path)
PY

WORKDIR /workspace

CMD ["/bin/bash"]
