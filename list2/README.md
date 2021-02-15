# Języki-Formalne-i-Teoria-Translacji
## Lista 2

Analiza leksykalna. <br>

Wszystkie programy sa napisane we FLEX-ie.

### Zadanie 1
Program który czyta dowolny plik tekstowy, usuwa w nim wszystkie białe znaki na końcu i na początku wiersza, zmienia wszystkie wystąpienia ciągów tabulatorów i spacji na dokładnie jedną spację, likwiduje puste linie, oraz na końcu dopisuje liczbę linii i słów (ciągi znaków oddzielone białymi znakami).

Przykład wywołania
```Shell
$ make
$ ./zad1 < data/text.txt
```

### Zadanie 2
Program który usuwa wszystkie komentarze w plikach źródłowych języka Python.

Przykład wywołania
```Shell
$ make
$ ./zad2 < data/program.py
```

### Zadanie 3
Program który usuwa wszystkie komentarze w programach napisanych w języku C++, a po włączeniu odpowiedniej opcji pozostawia komentarze dokumentacyjne (wg.Doxygen-a co najmniej następujące/**,/*!,///i//!) i usuwa pozostałe.

Przykład wywołania
```Shell
$ make
$ ./zad3 < data/program.cpp
$ ./zad3 docs < data/program.cpp
```

### Zadanie 4
Prosty kalkulator postfiksowy (odwrotna notacja polska) dla liczb całkowitych wykonujący operacje dodawania (+), odejmowania (-), mnożenia (*),dzielenia całkowitoliczbowego (/), potęgowania (^) i modulo (%).  Wyrażenie do policzenia powinno być napisane w jednej linii. Program powinien wyświetlać dla każdej linii wynik albo komunikat o błędzie (jak najbardziej szczegółowy).

Przykład sesji
```Shell
$ make
$ ./zad4
$ 2 3+4*
$ = 20
$ 1 2 3 4 + * -
$ = -13
$ -1 2 -3 4 + * -
$ = -3
$ 8 -7 6 -5 4 * -3 % / - +
$ = 4
$ 2 3 2 ^ ^
$ = 512
$ 2 3+*
$ Too few arguments
$ 2 3 4 +
$ Too few operators
$ 2.4 3+
$ Wrong char : '.'
```
