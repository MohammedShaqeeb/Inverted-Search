# 🔍 Inverted Search using Hash Table in C

## 📌 Overview

This project is a **console-based Inverted Search System** written in C that allows users to efficiently index and search words from multiple text files.

The project uses **Hash Tables and Linked Lists** to store and retrieve words quickly along with their corresponding file details and occurrence counts.

It demonstrates important concepts like **Data Structures, Dynamic Memory Allocation, File Handling, Hashing, and Modular Programming**.

---

## 🚀 Features

* 📂 Create database from multiple `.txt` files
* 🔍 Search words efficiently
* 📋 Display complete database
* 💾 Save database into backup file
* 🔄 Restore database from backup file
* ❌ Delete entire database and free memory
* ✅ File validation support
* 🚫 Duplicate file prevention
* ⚡ Fast searching using Hash Table

---

## 🛠️ Technologies Used

* **Language:** C
* **Concepts:**

  * Hash Tables
  * Linked Lists
  * Dynamic Memory Allocation
  * File Handling
  * Structures
  * Strings
  * Modular Programming

---

## 📂 Project Structure

```text
├── main.c            # Menu-driven main program
├── create_db.c       # Database creation logic
├── display_db.c      # Display database contents
├── search_db.c       # Search functionality
├── save_db.c         # Save database to backup file
├── update_db.c       # Restore database from backup
├── delete_db.c       # Delete and free database
├── inv.h             # Structure definitions and declarations
└── README.md         # Project documentation
```

---

## ⚙️ How It Works

1. User provides multiple `.txt` files as command-line arguments.
2. Program reads each file word by word.
3. Words are indexed using a Hash Table.
4. Each word stores:

   * Number of files containing it
   * File names
   * Occurrence count
5. User can search, display, save, or restore the database using menu operations.

---

## 🧪 Sample Menu

```text
----------
MAIN MENU:
----------
1. Create Database
2. Search Database
3. Display Database
4. Save Database
5. Update Database
6. Exit
----------
```

---

## ▶️ How to Compile and Run

### Compile:

```bash
gcc *.c
```

OR

```bash
gcc main.c create_db.c display_db.c search_db.c save_db.c update_db.c delete_db.c -o inverted_search
```

---

### Run:

```bash
./a.out file1.txt file2.txt
```

OR

```bash
./inverted_search file1.txt file2.txt
```

---

## 📊 Database Storage Format

The backup database is stored in the following format:

```text
#7;hello;2;file1.txt;4;file2.txt;2;#
```

### Format Explanation

```text
#index;word;filecount;filename;wordcount;...;#
```

---

## 🔒 Validations Implemented

* ✅ Only `.txt` files are accepted
* ✅ Empty files are rejected
* ✅ Duplicate files are prevented
* ✅ Backup file format validation
* ✅ File existence checking

---

## 🧠 Data Structures Used

### 📌 Hash Table

A Hash Table of size **27** is used.

| Index  | Stores                       |
| ------ | ---------------------------- |
| 0 - 25 | Words starting with a-z/A-Z  |
| 26     | Special characters / numbers |

---

### 📌 Main Node

Stores:

* Word
* File count
* Link to sub nodes
* Link to next main node

```c
typedef struct main_node
{
    char *word;
    int f_count;
    sub *sub_link;
    struct main_node *m_link;
}main_t;
```

---

### 📌 Sub Node

Stores:

* File name
* Word occurrence count
* Link to next sub node

```c
typedef struct sub_node
{
    char *fname;
    int w_count;
    struct sub_node *s_link;
}sub;
```

---

## 🔍 Search Example

```text
Enter the Word to be found: hello

hello is present in 2 files!

-> file1.txt has 4 occurrences
-> file2.txt has 2 occurrences
```

---

## 📋 Display Example

```text
--------------------------------------------------------------------------
Index  Word            FileCount   Filename             WordCount
--------------------------------------------------------------------------
7      hello           2
                                     file1.txt          4
                                     file2.txt          2
--------------------------------------------------------------------------
```

---

## 📈 Future Improvements

* 🔤 Case-insensitive searching
* 🧹 Better punctuation handling
* 📦 Dynamic Hash Table resizing
* 🖥️ GUI implementation
* ⚡ Trie-based optimization
* 🔍 Partial word searching

---

## 👨‍💻 Author

**Mohammed Shaqeeb**

---

## 📅 Project Duration

* **Start Date:** 27-04-2026
* **End Date:** 07-05-2026

---

## 📜 License

This project is open-source and free to use for learning purposes.
