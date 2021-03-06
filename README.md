ASSESSMENT 
==========

8.9/15b ([assessment report](https://github.com/ldrahnik/ial_project_2017_2018/issues/2))

SHREYA - Nejkratší cesta v grafu
============

Program hledá nejkratší cestu v grafu mezi dvěma zadanými vrcholy. Pokud není explicitně uvedeno zda se jedná o ohodnocený (`-r`) nebo neohodnocený (`-u`) graf, nastaví se automaticky ohodnocený v případě nalezení alespoň 1 ohodnocené hrany. Orientovanost (`-o`) je nutné vždy explicitně vyžádat argumentem.

## Příklad spuštění:

```
./shreya -h
The shorted path in graph between two vertices. If the type of graph would be not explicitly defined by options are automatically defined from graph.

Example of usage:

./shreya [-h ] [-r] [-o] [-i <graph_path as string>] <vertice_start> <vertice_end>

Options:
-r -- rated graph
-u -- non-rated graph
-o -- oriented graph
-h -- show help message
-i -- string contains graph_path (for example rated graph vertice0 -> 4 -> vertice1)
<vertice> -- name of valid vertice (first is start, second is end)
```

## Omezení programu:

## Rozšíření programu:

Přidaný volitelný debugovací parametr `[-d]`.

Program neimplementuje jeden algoritmus, ale více: `Bellman Ford`, `Dijkstra`, `Floyd Warshall` a `Johnson` (kombinuje `Bellman Ford` a `Dijkstra`).

## Testování programu:

```
make test
bash ./tests/_run-tests.sh /home/ldrahnik/projects/ial_project_2017_2018 /home/ldrahnik/projects/ial_project_2017_2018/tests/log /home/ldrahnik/projects/ial_project_2017_2018/tests/ /home/ldrahnik/projects/ial_project_2017_2018/graphviz/convert_script.py
bash ./tests/_run-tests-diff.sh /home/ldrahnik/projects/ial_project_2017_2018 /home/ldrahnik/projects/ial_project_2017_2018/tests/log /home/ldrahnik/projects/ial_project_2017_2018/tests/
*******TEST test01 PASSED
*******TEST test02 PASSED
*******TEST test03 PASSED
*******TEST test04 PASSED
*******TEST test05 PASSED
*******TEST test06 PASSED
*******TEST test07 PASSED
*******TEST test08 PASSED
rm -rf /home/ldrahnik/projects/ial_project_2017_2018/tests/log/*
```

## Odevzdané soubory:

```
xdrahn00
├── Makefile
├── manual.pdf
├── src
│   ├── algorithm
│   │   ├── bellman_ford.c
│   │   ├── bellman_ford.h
│   │   ├── dijkstra.c
│   │   ├── dijkstra.h
│   │   ├── floyd_warshall.c
│   │   ├── floyd_warshall.h
│   │   ├── johnson.c
│   │   └── johnson.h
│   ├── error.h
│   ├── graph.c
│   ├── graph.h
│   ├── params.c
│   ├── params.h
│   ├── results.c
│   ├── results.h
│   ├── shreya.c
│   └── shreya.h
└── tests
    ├── .gitignore
    ├── log
    │   └── .gitkeep
    ├── _run-tests-diff.sh
    ├── _run-tests.sh
    ├── test01.in
    ├── test01.out
    ├── test01.png
    ├── test02.in
    ├── test02.out
    ├── test02.png
    ├── test03.in
    ├── test03.out
    ├── test03.png
    ├── test04.in
    ├── test04.out
    ├── test04.png
    ├── test05.in
    ├── test05.out
    ├── test05.png
    ├── test06.in
    ├── test06.out
    ├── test06.png
    ├── test07.in
    ├── test07.out
    ├── test07.png
    ├── test08.in
    ├── test08.out
    └── test08.png

4 directories, 47 files
```
