
---

# **Student Database Management System**

## **Description**

This program, written in **C**, is a command-line student database management system. It allows you to add, delete, update, and sort student records stored in a text file.

---

## **Features**

1. **Add Student**  
   Add a new student to the database.

2. **Delete Student**  
   Remove a student from the database based on their details.

3. **Update Student**  
   Modify the information of an existing student.

4. **Display Students**  
   Print students of a specific class with sorting options (by name, surname, or age).

---

## **Compilation**

The project uses a **Makefile** for compilation. To build the project, run:

```bash
make all
```

To clean up temporary files, use:

```bash
make clean
```

---

## **Usage**

### 1. **Add a Student**

```bash
./main add <Name> <Surname> <Age> <ClassName>
```

**Example:**
```bash
./main add Dima Pro 12 px-22
```

---

### 2. **Delete a Student**

```bash
./main delete <Name> <Surname> <Age> <ClassName>
```

**Example:**
```bash
./main delete Dima Pro 12 px-22
```

---

### 3. **Update a Student**

```bash
./main change <Name> <Surname> <Age> <ClassName> <NewName> <NewSurname> <NewAge> <NewClassName>
```

**Example:**
```bash
./main change Dima Pro 12 px-22 Artem Ivanov 15 px-23
```

---

### 4. **Print Students (Sorted)**

```bash
./main print <ClassName> <SortOption>
```

- **`<ClassName>`**: The class name (e.g., `px-22`).
- **`<SortOption>`**: Sorting criteria: `age`, `name`, or `surname`.

**Example:**
```bash
./main print px-22 age
```

**Output:**
```
name: Timur, surname: Koselek, age: 13, class: px-22
name: Ja, surname: Ne, age: 100, class: px-22
```

---

## **Data File**

Student data is stored in a text file named **`students.txt`**. Each student is represented by a single line in the following format:

```
<Age> <Name> <Surname> <ClassName>
```

**Example:**
```
12 Dima Pro px-22
13 Timur Koselek px-22
100 Ja Ne px-22
```

---

## **Project Structure**

The project directory contains the following files:

```
.
├── Makefile
├── main.c
├── student_add.c
├── student_add.h
├── student_change.c
├── student_change.h
├── student_sorting.c
├── student_sorting.h
├── file_change.c
├── file_change.h
├── students.h
└── students.txt
```

- **main.c**: The entry point of the program.
- **student_add.c/h**: Handles adding students.
- **student_change.c/h**: Handles updating and deleting students.
- **student_sorting.c/h**: Provides sorting functionality.
- **file_change.c/h**: Handles loading and saving data to/from `students.txt`.
- **students.h**: Defines the student data structure.
- **students.txt**: The text file where student records are stored.

---

## **System Requirements**

- **GCC Compiler** supporting the **C99 standard**.
- A Unix-like environment (Linux, macOS, or WSL on Windows).

---

## **Building and Running the Program**

1. **Compile the program**:
   ```bash
   make all
   ```

2. **Run the program with a command**:
   ```bash
   ./main [command] [arguments]
   ```

3. **Clean up build files**:
   ```bash
   make clean
   ```

---

## **Examples**

**Add a student:**
```bash
./main add Alice Johnson 20 px-23
```

**Delete a student:**
```bash
./main delete Alice Johnson 20 px-23
```

**Update a student:**
```bash
./main change Alice Johnson 20 px-23 Alina Petrova 21 px-24
```

**Print students sorted by age:**
```bash
./main print px-23 age
```

---
