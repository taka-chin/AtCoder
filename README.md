# AtCoder 開発環境

AtCoder 用の C++ 開発環境です。

以下の 2 つの環境を用意しています。

- Docker（Ubuntu 環境を再現）
- Nix（macOS ネイティブ環境）

---

# 使用ツール

- C++23
- clang / clang++
- clangd
- lldb（macOS）
- atcoder-cli (acc)
- online-judge-tools (oj)
- Vim
- tmux

---

# ディレクトリ構成

```text
.
├── Dockerfile
├── docker-compose.yml
├── flake.nix
├── flake.lock
└── workspace/
```

---

# Docker 環境

## 初回セットアップ

```bash
docker compose build
```

Dockerfile を変更した場合のみ再実行します。

キャッシュを無視する場合

```bash
docker compose build --no-cache
```

---

## 起動

```bash
docker compose run --rm atcoder
```

終了

```bash
exit
```

---

## 疎通確認

```bash
g++ --version
gdb --version
clangd --version
oj --version
acc --version
```

---

# Nix 環境（macOS 推奨）

## 初回セットアップ

Nix をインストールします。

```bash
nix --version
```

初回のみ lock ファイルを生成します。

```bash
nix develop
```

---

## 起動

```bash
nix develop
```

終了

```bash
exit
```

---

## 疎通確認

```bash
type -a clang
type -a clang++
type -a clangd
type -a lldb
type -a python3
type -a oj
type -a acc
```

Nix 管理されているツールは

```text
/nix/store/...
```

から実行されます。

---

# AtCoder ログイン

確認

```bash
oj login --check https://atcoder.jp/
```

ログイン

```bash
oj login https://atcoder.jp/
```

---

# 問題取得

```bash
cd workspace

acc new abc460
```

問題へ移動

```bash
cd abc460/a
```

---

# コンパイル

## Docker

```bash
g++ -std=c++23 main.cpp
```

## Nix

```bash
clang++ -std=c++23 main.cpp
```

---

# サンプルテスト

```bash
oj t
```

---

# 提出

```bash
acc submit main.cpp
```

または

```bash
oj submit \
  https://atcoder.jp/contests/abc460/tasks/abc460_a \
  main.cpp \
  -l 6017 \
  -y
```

> AtCoder 側で CAPTCHA / Cloudflare Turnstile が有効な場合は CLI 提出できないことがあります。
> その場合はブラウザから提出してください。

---

# Vim / tmux

Docker 環境ではホストの設定をマウントします。

```text
~/.vimrc
~/.vim
~/.tmux.conf
```

Nix 環境ではホストの設定がそのまま利用されます。

---

# Git

通常どおり利用できます。

```bash
git status
git pull
git push
```

---

# 永続化されるデータ

## Docker

### Volume

- atcoder_config
- oj_cookie
- vim_lsp_settings
- vim_cache
- vim_undo

### ホスト

- workspace
- ~/.vim
- ~/.vimrc
- ~/.tmux.conf

---

## Nix

ホスト側に保存されます。

```text
workspace/
~/.config/atcoder-cli-nodejs
~/.local/share/online-judge-tools
~/.vim
~/.vimrc
~/.tmux.conf
```

---

# よく使うコマンド

## Docker 起動

```bash
docker compose run --rm atcoder
```

## Nix 起動

```bash
nix develop
```

## 問題取得

```bash
acc new abc460
```

## サンプルテスト

```bash
oj t
```

## 提出

```bash
acc submit main.cpp
```

## ログイン確認

```bash
oj login --check https://atcoder.jp/
```

## 終了

```bash
exit
```
