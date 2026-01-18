# 🎓 Student Grade Manager (SAE 1.01)

![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Institution](https://img.shields.io/badge/School-IUT_Amiens-EC1C24?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

## 📄 Description

This project is a **Student Grade Management System** developed in **C** as part of the **SAE 1.01** (Situation d'Apprentissage et d'Évaluation) at the IUT of Amiens (BUT Informatique).

The program allows users to input multiple subjects, manage student grades dynamically, calculate averages automatically, and generate a ranked report of students based on their performance.

## ✨ Features

* **Dynamic Configuration:** Define the number of subjects and evaluations per subject.
* **Data Entry:** Input grades for up to 50 students across different subjects.
* **Automatic Calculations:**
    * Average per subject.
    * General average (GPA equivalent).
* **Ranking System:** Sorts students from highest to lowest general average using a **Bubble Sort algorithm**.
* **Detailed Reporting:** Displays a structured report card for every student.

## 🛠️ Technical Details

This project demonstrates mastery of fundamental C concepts:

* **Multi-dimensional Arrays:** Uses a 3D array structure to store grades:
    ```c
    // [Student ID] [Subject ID] [Grade Index]
    float notes[MAX_ELEVES][MAX_MATIERES][MAX_NOTES];
    ```
* **Algorithmic Logic:** Implementation of loops, conditional structures, and sorting algorithms.
* **Input Handling:** Management of buffer clearing and string inputs (`fgets`, `scanf`).

## 🚀 How to Run

### Prerequisites
You need a C compiler (like `gcc`) installed on your machine.

### Installation & Execution

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/ton-pseudo/student-grade-manager.git](https://github.com/ton-pseudo/student-grade-manager.git)
    cd student-grade-manager
    ```

2.  **Compile the source code:**
    ```bash
    gcc main.c -o grade_manager
    ```

3.  **Run the program:**
    * **Windows:**
        ```bash
        .\grade_manager.exe
        ```
    * **Mac/Linux:**
        ```bash
        ./grade_manager
        ```

## 👤 Author

**Noa** - Student @ IUT Amiens
* [My GitHub Profile](https://github.com/ton-pseudo)

---
*Project created for the Bachelor University of Technology (BUT) in Computer Science - Semester 1.*
