# Języki-Formalne-i-Teoria-Translacji
## Lista 1

Program wyszukuje wzorzec w podanym pliku z kodowaniem utf8.<br />
Na standardowym wyjściu program podaje indeksy, na których pojawia się wzorzec (indeksy są numerowane od zera).

```Shell
$ ./FA <pattern> <filename>
```

Przykład wywołania
```Shell
$ make
$ ./FA 'pattern' text.txt
$ ./KMP 'pattern' text.txt
```

