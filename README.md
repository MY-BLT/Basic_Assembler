# Assembler Project

## توضیحات پروژه

این پروژه یک اسمبلی ساده است که برنامه‌های نوشته شده به زبان اسمبلی را به کد ماشین تبدیل می‌کند. این اسلاید به شما کمک می‌کند برای درک بهتر کارکرد پروژه و نحوه استفاده از آن، اطلاعات لازم را بدست آورید.

## بررسی پروژه

این پروژه شامل دو قسمت اصلی است:
- **گذر اول**: شناسایی برچسب‌ها و آماده‌سازی جدول نمادها.
- **گذر دوم**: تبدیل دستورات به کد ماشین و نوشتن نتایج در یک فایل خروجی.

### نحوه استفاده

1. فایل اسمبلی خود را با پسوند `.asm` در پوشه `input` قرار دهید.
2. برنامه را اجرا کنید و نام فایل (بدون پسوند) را وارد کنید.
3. فایل خروجی که شامل کد ماشین است به صورت `fileName.out` در پوشه `output` ذخیره خواهد شد.

### نیازمندی‌ها

برای اجرای این برنامه به هدر `C++` و کتابخانه‌های استاندارد شامل `<iostream>`, `<fstream>`, `<sstream>`, و `<unordered_map>` نیاز دارید. 

### ساختار پوشه پروژه
- **AssemblerProject**
  - **input** 
    - yourfile.asm
  - **output** 
    - yourfile.out
  - **src**
    - main.cpp
    - assembler.h
    - assembler.cpp
    - table.h
    - table.cpp
    - error.h
    - error.cpp

## English Version

# Assembler Project

## Project Description

This project is a simple assembler that converts programs written in assembly language into machine code. This document will help you understand the functionality of the project and how to use it.

## Project Structure

The project consists of two main parts:
- **First Pass**: Identifying labels and preparing the symbol table.
- **Second Pass**: Converting instructions to machine code and writing the results to an output file.

### How to Use

1. Place your assembly file with a `.asm` extension in the `input` folder.
2. Run the program and enter the filename (without the extension).
3. The output file containing the machine code will be saved as `fileName.out` in the `output` folder.
