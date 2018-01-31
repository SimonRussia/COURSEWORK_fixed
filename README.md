<img src="http://abali.ru/wp-content/uploads/2013/03/Gerb_MGTU_imeni_Baumana.png" width="160" height="whatever" align="right">

[![Build Status](https://travis-ci.org/SimonRussia/COURSEWORK_fixed.svg?branch=master)](https://travis-ci.org/SimonRussia/COURSEWORK_fixed) [![codecov](https://codecov.io/gh/SimonRussia/COURSEWORK_fixed/branch/master/graph/badge.svg)](https://codecov.io/gh/SimonRussia/COURSEWORK_fixed) [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](/LICENSE)

## Курсовой проект
Тема: ***Реализация основных алгоритмов сортировок***

## ISSUE
- [X] Устранить недостатки в коде;
  > *форматированный код.*
- [X] Реализовать основные алгоритмы сортировок шаблонного типа (**через итераторы**);
  >***merge**(RandomAccessIterator **left**, RandomAccessIterator **medium**, RandomAccessIterator **right**)*
- [X] Применить новые возможности в **С++11**;
  >***#include* <*iterator>*** *std::begin() std::end()*
  >
  >***#include* <*chrono>*** *генератор случайных чисел.*
- [X] Выбрать более оптимальный способ выделение памяти в реализованные алгоритмах;
  >***new delete***
- [X] Отредактировать **CMakeLists.txt**;
  >*add_liabrary HEADER ONLY*
- [X] Оценить реализованные алгоритмы по вермени (размерность **nanoseconds**).

**<< draggable table >>**

| algorithm | 1.000 | 10.000 | 100.000 | 1.000.000 | 10.000.000 | 100.000.000 | 1.000.000.000|
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| **BUCKET** | 161.564 | 1.255.806 | 11.152.815 | ❌ | ❌ | ❌ | ❌ |
| **MERGE** | 445.023 | 5.204.281 | 37.645.747 | 344.570.245 | 3.372.794.205 | 35.314.297.619 | 392.595.809.242 |
| 🐇 **RADIX** | 99.725 | 785.728 | 8.212.912 | 64.553.554 | 560.186.829 | 5.922.167.995 | 64.071.364.009 |
| 🐢 **SELECTION** | 1.671.141 | 114.266.805 | 11.170.449.505 | 1.073.728.869.602 | 💤 | 💤 | 💤 |

| emoji | legend |
| :---: |---|
|❌ | **std::vector** error: Segmentation fault 11 «*» |
|💤 | обработка массива данных займет > 24 часов.|
|🐇 | оптимальная по времени сортировка.|
|🐢 | худшая по времени сортировка.|

  > В данной реализации применяется std::vector для разбиения по корзинам. Из-за ограничения std::vector массив >= 1.000.000 не обрабатывается.

---

## Техническое задание
- [X] Реализовать основные алгоритмы сортировок с использование шаблонных функций языка **C++**;
- [X] Тестирование разработанных алгоритмов с использованием  фреймворка для модульного тестирования **Catch**;
- [X] Обеспечение **100%** покрытия кода;
- [X] Рассмотреть возможность оптимизации при реализации алгоритмов направленных на работу в мультизадачных системах.

## Статический анализ кода
| check | algorithm | cpplint report | cppcheck report | OCLint report |
| :---: | --- | --- | --- | --- |
| ☑️ | **BUCKET** | Done processing bucket.hpp | Checking bucket.hpp ... | Summary: TotalFiles=1 FilesWithViolations=0 P1=0 P2=0 P3=0 |
| ☑️ | **MERGE** | Done processing merge.hpp | Checking merge.hpp ... | Summary: TotalFiles=1 FilesWithViolations=0 P1=0 P2=0 P3=0 |
| ☑️ | **RADIX** | Done processing radix.hpp | Checking radix.hpp ... | Summary: TotalFiles=1 FilesWithViolations=0 P1=0 P2=0 P3=0 |
| ☑️ | **SELECTION** | Done processing selection.hpp | Checking selection.hpp ... | Summary: TotalFiles=1 FilesWithViolations=0 P1=0 P2=0 P3=0 |

## Визуализация алгоритмов сортировок
| Bucket | Merge | Radix | Selection |
| --- | --- | --- | --- |
| <img src="http://sorting.valemak.com/wp-content/uploads/2013/12/sort_bucket.gif" width="300" height="whatever"> | <img src="http://sorting.valemak.com/wp-content/uploads/2013/11/sort_merge.gif" width="300" height="whatever"> | <img src="http://sorting.valemak.com/wp-content/uploads/2013/12/sort_radix_lsd.gif" width="300" height="whatever"> | <img src="http://sorting.valemak.com/wp-content/uploads/2013/11/sort_selection.gif" width="300" height="whatever"> |
