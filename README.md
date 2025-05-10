# 📜 get\_next\_line

### *Because reading a file line by line shouldn't feel like a punishment.*

---

## 📝 About the Project

In this project, you will implement **`get_next_line`**, a function that reads and returns the next line from a file descriptor, one call at a time.

While it may seem simple, this project challenges you to master **file handling**, **buffered reading**, and especially the correct use of **static variables**.

Once completed, your **`get_next_line`** function will be a powerful tool that can handle reading any file or standard input stream efficiently, one line at a time.

---

## 🚀 Getting Started

### Prerequisites

* A C compiler (e.g., `cc`, `gcc`, `clang`)
* Norminette-compliant code
* Compilation flags: `-Wall -Wextra -Werror`

---

## 🛠️ Installation

```bash
git clone https://github.com/matusala3/get_next_line.git
cd get_next_line
make
```

This will prepare your project for testing and integration.

---

## ⚙️ Usage

### Function Prototype

```c
char *get_next_line(int fd);
```

### Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("sample.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

### Compilation Example

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

> **Note:** You can change `BUFFER_SIZE` to test different reading behaviors.

---

## 🭹 Features

* Reads **one line at a time**, including the newline `\n` character if present.
* Returns **NULL** when EOF is reached or an error occurs.
* Works with **any valid file descriptor**, including `stdin`.
* **Efficient memory management** with no leaks.
* **Configurable BUFFER\_SIZE** at compile time.

---

## 🎯 Bonus Features

* **Single static variable management**
* **Simultaneous multi-file descriptor support**, preserving read state for each one independently

Bonus files:

* `get_next_line_bonus.c`
* `get_next_line_bonus.h`
* `get_next_line_utils_bonus.c`

> **Note**: The bonus part will only be evaluated if the mandatory part is fully functional.

---

## 🛠️ Development Guidelines

* **Language**: C
* **Coding Standard**: *42 Norminette*
* **Compilation Flags**: `-Wall -Wextra -Werror`
* **Memory Safety**: No leaks, no crashes, no undefined behavior
* **Makefile Rules**:

  * `all`, `clean`, `fclean`, `re`, `bonus`

---

## 🥪 Testing

You are strongly encouraged to develop **your own test programs**.

Consider edge cases like:

* `BUFFER_SIZE` = 1
* Very large `BUFFER_SIZE`
* Reading from `/dev/stdin`
* Empty files
* Files with no newline at EOF
* Binary files (undefined behavior)

---

## 👥 Credits

Developed by:
**Matusala Gebrehiwot**

---

## 📄 License

This project is part of the **42 School Curriculum** and is intended for educational purposes.