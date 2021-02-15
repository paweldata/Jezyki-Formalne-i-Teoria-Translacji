# Języki-Formalne-i-Teoria-Translacji
## Lista 3

Analiza leksykalna i składniowa. <br>

Translator wyrażeń arytmetycznych w ciele Z (1234577) z postaci infiksowej do postaci postfiksowej (odwrotnej notacji polskiej), z korekcją postaci liczby (w Zp nie ma liczb ujemnych i większych lub równych p), i podającej wynik obliczenia wyrażenia. Wyrażenia do policzenia umieszczone są w osobnych liniach. Program ma przetwarzać wszystkie linie wejścia, a linie zaczynające się od # traktować jak linie komentarza i omijać. W przypadku długich linii ma być możliwość ich podzielenie za pomocą znaku \ (tak jak w języku c).

### Zadanie 1
W języku C (FLEX i BISON)

Przykład wywołania
```Shell
$ cd zad1
$ make
$ ./calculator
```

### Zadanie 2
W języku Python (PLY) <br>

W folderze zad2/ obok calculator.py powinien się znaleźć folder ply/ <br>
https://www.dabeaz.com/ply/ <br>

Przykład wywołania
```Shell
$ cd zad2
$ python3 calculator.py
```

### Przykład sesji
```Shell
$ 2+3*(4-5)
$ 2 3 4 5 - * + 
$ Result : 1234576
$ 2^100
$ 2 100 ^ 
$ Result : 295422
$ # ala ma kota
$ 2-3-2
$ 2 3 - 2 - 
$ Result : 1234574
$ 269164/123456
$ 269164 123456 / 
$ Result : 567890
$ -2--1
$ 1234575 1234576 - 
$ Result : 1234576
$ 1/-580978
$ 1 653599 / 
$ Result : 123456
$ 123456789
$ 1233666 
$ Result : 1233666
$ -1234567
$ 10 
$ Result : 10
$ 2+3*(4-5
$ Error
$ 2^123
$ 2 123 ^ 
$ Result : 594706
$ 2^-2
$ 2 1234574 ^ 
$ Result : 925933
```
