# libft

`libft` is a custom C library replicating the functionality of the standard C library with additional functionality to facilitate common programming tasks. This project serves both as a learning tool for understanding how standard library functions work under the hood and as a useful library for C projects requiring a lightweight, standalone library.

## Overview

This library includes a range of functions from the standard C library, along with additional utilities that are often needed in various projects. Functions are divided into several categories such as string manipulation, memory allocation, character checks, and mathematical operations.

## Features

- **String Functions:** Functions like `ft_strlen`, `ft_strcpy`, `ft_strdup`, providing custom implementations of standard string manipulation routines.
- **Memory Functions:** Includes `ft_memset`, `ft_memcpy`, which allow direct manipulation of memory areas.
- **Utility Functions:** Additional utilities like `ft_atoi`, `ft_itoa` for converting strings to integers and vice versa.
- **Linked List Management:** Functions for creating and managing linked lists, such as `ft_lstnew`, `ft_lstadd_front`.

## Getting Started

### Prerequisites

Ensure you have a C compiler such as `gcc` or `clang` and `make` installed on your system to build the library.

### Compilation

Clone the repository and compile the library using `make`:

```bash
git clone https://github.com/Fayeza99/libft.a.git
cd libft.a
make
