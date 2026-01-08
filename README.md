# clip (clipx)

Cross-platform clipboard utility: stdin → clipboard, clipboard → stdout

**`clipx` is a small, cross-platform command-line clipboard utility.**  
It gives you a single, consistent way to copy *to* and paste *from* the system clipboard — everywhere.

No more remembering `pbcopy`, `pbpaste`, `xclip`, `wl-copy`, PowerShell commands, or wondering what’s installed.

---

## Why `clipx`?

Every platform solved the clipboard differently:

- macOS: `pbcopy`, `pbpaste`
- Linux: `xclip`, `xsel`, `wl-copy`, `wl-paste`
- Windows: `clip` (copy only, no paste)

That forces you to **think every time**.

`clipx` removes that friction.

Once installed, you can just do:

```sh
… | clipx
clipx -p
```

And move on.

---

## Usage

### Copy stdin → clipboard

```sh
echo "hello world" | clipx
cat file.txt | clipx
```

This behavior is **fully compatible** with Windows’ built-in `clip`.

---

### Paste clipboard → stdout

```sh
clipx -p
clipx --paste
```

Useful for redirecting directly into files:

```sh
clipx -p > newfile.cpp
```

Or piping:

```sh
clipx -p | sed 's/foo/bar/g'
```

---

## Typical workflows

### Save copied code directly to a file

```sh
clipx -p > script.sh
chmod +x script.sh
git add script.sh
git commit -m "Add script"
```

### AI → clipboard → file → git

```sh
runai -t "Generate helper script" | clip
clip -p > helper.sh
```

No editor. No mouse. No context switching.

---

## Platforms & backends

`clipx` automatically selects the appropriate backend:

- **Windows**
  - Copy: `clip`
  - Paste: `Get-Clipboard` (PowerShell)

- **macOS**
  - `pbcopy`, `pbpaste`

- **Linux**
  - Wayland: `wl-copy`, `wl-paste`
  - X11: `xclip` or `xsel`

If no suitable backend is found, `clipx` prints a clear error message.

---

## What `clipx` does *not* do (by design)

- ❌ No GUI
- ❌ No file copying
- ❌ No image handling (text only)
- ❌ No configuration

`clipx` is meant to be **small, predictable, and composable**.

---

## Build

Requirements:
- C++17 compiler
- CMake ≥ 3.10

```sh
cmake -S . -B build
cmake --build build
```

The resulting binary is `clipx`.

---

## Philosophy

- One command
- One name
- Same behavior everywhere
- Zero thinking required

If you stop noticing `clipx`, it’s doing its job.

---

## Author

David Joffe
https://davidjoffe.github.io/

## License

MIT

Copyright © 2026 David Joffe
