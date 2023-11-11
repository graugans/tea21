# Kommandozeilen Parameter

Folgendes kurzes C++ Programm erläutert die Parmeter `int argc` und `char** argv` anhand eines Beispiels.

Gegeben ist folgender Programm Auszug:

```cpp
auto main(int argc, char **argv) -> int
{
    fmt::println("Amount of parameters provided: {}",argc);
    for (auto i : std::views::iota(0, argc)) {
        fmt::println("argv[{}][{}\\0]",i,argv[i]);
    }
    return 0;
}
```

Wird das Programm wie folgt aufgerufen `./build/bin/example-001 --version --count` lautet die Ausgabe:

```sh
Amount of parameters provided: 3
argv[0][./build/bin/example-001\0]
argv[1][--version\0]
argv[2][--count\0]
```

Rufen wir das Programm ohne Parameter auf `./build/bin/example-001` so lautet die Ausgabe:

```sh
Amount of parameters provided: 1
argv[0][./build/bin/example-001\0]
```

Verändern wir den Pfad von relativ zu absolut `/workspaces/tea21/build/bin/example-001` so verändert sich die Ausgabe folgendermaßen:

```sh
Amount of parameters provided: 1
argv[0][/workspaces/tea21/build/bin/example-001\0]
```

Mit Hilfe der obigen Beispiele wird sehr schnell klar, dass der erste Parameter der Funktion `main` mit dem Namen `argc` angibt wie viele Argumente an das aktuelle Programm übergeben wurden und der zweite Parameter `argv` die Parameter selbst beinhaltet.

```cpp
auto main(int argc, char **argv) -> int
```

Beim zweiten Parameter handelt es sich um ein `char**`, das heißt ein Array von Zeigern auf `char[]` diese sind jeweils Null terminiert `\0`. Im ersten Eintrag befindet sich immer der gesamte Aufrufpfad der ausführbaren Datei.

## Parsen der Kommandozeilenargumente

Da das Parsen der Kommandozeilenargumente sehr schnell aufwändig und Fehleranfällig werden kann verwenden wir stattdessen die Bibliothek [CLI11](https://cliutils.github.io/CLI11/book/)

```cpp
#include "CLI/CLI.hpp"
#include <fmt/format.h>

int main(int argc, char **argv) {
    CLI::App app{"App description"};

    // Define options
    int p = 0;
    app.add_option("-p", p, "Parameter");

    CLI11_PARSE(app, argc, argv);

    fmt::println("Parameter value: {}",p);
    return 0;
}
```
