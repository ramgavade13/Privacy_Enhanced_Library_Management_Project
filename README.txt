Privacy-Enhanced Library Management System with Encrypted Login
------------------------------------------------------------------
Project Name  : LMS_APP - Library Management System
Developer     : Ram Gavade
College       : VIT Pune
Branch        : Computer Engineering (Second Year)
------------------------------------------------------------------

What is included:
- main.cpp                : Full C++ source code (single-file)
- users.txt               : (auto-created) stores registered users
                            as username|passwordHash
- books.txt               : (auto-created) stores books as
                            id|title|author|isIssued
- Project_Report.pdf      : Project report with problem statement,
                            flow, methodology, and instructions
- README.txt              : This file with instructions to
                            compile/run
- flutter_application_1/  : Flutter Mobile App (Frontend)
- backend/                : Flask REST API (Backend)
------------------------------------------------------------------

Tech Stack:
- Frontend  : Flutter (Mobile App)
- Backend   : Flask (Python REST API)
- Database  : MySQL
- C++ App   : Console-based LMS with password hashing
------------------------------------------------------------------

User Roles:
- Admin   : Books add/manage करतो
- Teacher : Books issue/return करतो
- Student : Books search/issue/return करतो
------------------------------------------------------------------

Features:
- Signup and Login with JWT Authentication
- Role-based Dashboard (Admin/Teacher/Student)
- Add / View / Search Books
- Issue and Return Books
- Fine System (Rs.10 per day late fee)
- Password Hashing (salted std::hash)
- Auto-creates users.txt and books.txt on first run
- Sample books added automatically if books.txt is missing
------------------------------------------------------------------

How to Run C++ App:
  Step 1: Open terminal in project folder
  Step 2: Compile using g++
          g++ main.cpp -o lms_app
  Step 3: Run
          ./lms_app  (Linux/Mac)
          lms_app.exe  (Windows)
------------------------------------------------------------------

How to Run Flutter App:
  Step 1: cd flutter_application_1
  Step 2: flutter pub get
  Step 3: flutter run
------------------------------------------------------------------

How to Run Flask Backend:
  Step 1: cd backend
  Step 2: pip install -r requirements.txt
  Step 3: python app.py
------------------------------------------------------------------

Notes:
- The project uses portable salted std::hash for password
  hashing (educational purpose).
- On first run, sample books are added automatically if
  books.txt is missing.
- users.txt and books.txt are created/updated in the same
  folder, keep them together with the executable.
- For stronger hashing (SHA-256), replace hash function
  with OpenSSL or a library implementation.
- If you want code split into multiple files
  (user.h/cpp, library.h/cpp), ask and it will be provided.
------------------------------------------------------------------

Contact:
- GitHub  : https://github.com/ramgavade13
- College : Vishwakarma Institute of Technology, Pune
------------------------------------------------------------------
