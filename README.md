# AtCoder Docker 開発環境

## 概要

AtCoder 用の C++ 開発環境。

以下を利用する。

* Docker
* atcoder-cli (acc)
* online-judge-tools (oj)
* GCC
* GDB
* clangd
* Vim
* tmux

---

## 初回セットアップ

Docker イメージを作成する。

```bash
docker compose build
```

Dockerfile を変更した場合のみ再度実行する。

キャッシュを無視して再構築したい場合のみ：

```bash
docker compose build --no-cache
```

---

## 起動

```bash
docker compose run --rm atcoder
```

終了：

```bash
exit
```

---

## 疎通確認

### GCC

```bash
g++ --version
```

### GDB

```bash
gdb --version
```

### clangd

```bash
clangd --version
```

### atcoder-cli

```bash
acc --version
```

期待値：

```text
2.2.0
```

### online-judge-tools

```bash
oj --version
```

期待値：

```text
online-judge-tools 11.5.1
```

### AtCoderログイン確認

```bash
oj login --check https://atcoder.jp/
```

成功例：

```text
[SUCCESS] You have already signed in.
```

---

## 問題取得

```bash
cd /workspace

acc new abc460
```

問題ディレクトリへ移動：

```bash
cd abc460/a
```

---

## サンプルテスト

コンパイル：

```bash
g++ -std=c++23 main.cpp
```

サンプル実行：

```bash
oj t
```

---

## 提出

通常：

```bash
acc submit main.cpp
```

または：

```bash
oj submit \
  https://atcoder.jp/contests/abc460/tasks/abc460_a \
  main.cpp \
  -l 6017 \
  -y
```

### 注意

AtCoder 側で CAPTCHA / Cloudflare Turnstile が有効な場合、

```text
× Error.
submission failed
```

となり CLI 提出が失敗することがある。

その場合はブラウザから提出する。

---

## Vim / tmux

ホストの設定ファイルを利用する。

```yaml
- ~/.vimrc:/root/.vimrc:ro
- ~/.vim:/root/.vim
- ~/.tmux.conf:/root/.tmux.conf:ro
```

### 既知の問題

* Iceberg の colorscheme が起動直後に正しく反映されない場合がある
* Vim の undo ディレクトリが存在しない場合は作成する

```bash
mkdir -p ~/.vim/undo
```

---

## Git

コンテナ内から利用可能。

```bash
git status
git pull
git push
```

推奨設定：

```yaml
- ~/.gitconfig:/root/.gitconfig:ro
- ~/.ssh:/root/.ssh:ro
```

---

## 永続化されるデータ

### Docker Volume

* atcoder_config
* oj_cookie

### ホスト共有

* workspace
* ~/.vim
* ~/.vimrc
* ~/.tmux.conf
* ~/.gitconfig
* ~/.ssh

---

## よく使うコマンド

### コンテナ起動

```bash
docker compose run --rm atcoder
```

### 問題作成

```bash
acc new abc460
```

### サンプルテスト

```bash
oj t
```

### 提出

```bash
acc submit main.cpp
```

### ログイン確認

```bash
oj login --check https://atcoder.jp/
```
