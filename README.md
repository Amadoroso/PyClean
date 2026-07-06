# PyClean

A lightweight, interactive Python utility designed to recursively find and purge Python bytecode (`__pycache__`) and static type-checker caches (`.mypy_cache`) from your project directories.

## ⚙️ Mechanics

Unlike standard shell commands (`find` + `rm -rf`), this script is entirely OS-independent. It uses Python's built-in libraries to safely handle directory traversal and removal:
* **`pathlib.Path.rglob`**: Recursively searches the current working directory for target cache folders using generator objects for memory efficiency.
* **`shutil.rmtree`**: Safely forces the deletion of directories and all their internal contents.

## Usage

Run the script from the root of the directory you want to clean:

```bash
python3 ft_pyclean.py

```

### Execution Flow

1. The script will prompt you with an interactive `[y/n]` confirmation to prevent accidental deletions.
2. If confirmed, it chains the search generators.
3. It prints a color-coded log of every directory removed.
4. It outputs the total number of cleaned cache folders.

## 📋 Requirements

* Python 3.x
* No external libraries or pip installations required (strictly uses standard built-ins: `pathlib`, `shutil`).
