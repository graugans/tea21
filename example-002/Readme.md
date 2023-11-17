# sizeof vs strlen vs size

## Go

Im Gegensatz zu Programmiersprachen wie Go oder Python funktioniert der Operator [sizeof](https://en.cppreference.com/w/cpp/language/sizeof) nicht wie die Eingebaute Funktion `len()` in Go:

```go
package main

import "fmt"

func main() {
	s := []int{2, 3, 5, 7, 11, 13}
	printSlice(s)

	// Slice the slice to give it zero length.
	s = s[:0]
	printSlice(s)

	// Extend its length.
	s = s[:4]
	printSlice(s)

	// Drop its first two values.
	s = s[2:]
	printSlice(s)
}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}
```

Das obige Beispiel kann [hier](https://go.dev/tour/moretypes/11) interaktiv ausprobiert werden.

```
len=6 cap=6 [2 3 5 7 11 13]
len=0 cap=6 []
len=4 cap=6 [2 3 5 7]
len=2 cap=4 [5 7]
```

Die Programmiersprache Go kennt keine Klassen, hier werden Methoden an Typen gebunden. Eine Methode ist eine Funktion mit einem Empfänger Argument.

```go
type Vertex struct {
	X, Y float64
}
func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}
```

Deshalb nutzt Go für die Berechnung der Länge eines Arrays oder Slice die Funktion `len()`, da Go bis vor einiger Zeit auch keine Generics (Templates) unterstützte. Was für eine Generische Methode `size` unabdingbar ist.


## C++
In C++ liefert der Operator `sizeof` die Größe in Byte des zu Grunde liegenden Datentyps.

```cpp
#include <fmt/format.h>
#include <vector>

auto main(int argc, char** argv) -> int
{
    char data[] = "None terminated string!!";
    std::vector<int> vec(100);
    int* pInt;
    fmt::println("The size of data[] {}",sizeof(data));
    fmt::println("The size of argv[0] {}",sizeof(argv[0]));
    fmt::println("The strlen of argv[0] {}",strlen(argv[0]));
    fmt::println("The sizeof(vec): {}",sizeof(vec));
    fmt::println("The vec.size(): {}",vec.size());
    fmt::println("The sizeof(pInt): {}",sizeof(pInt));
    return 0;
}

```

Wird das Programm wie folgt aufgerufen `./build/bin/example-002` lautet die Ausgabe:

```sh
The size of data[] 25
The size of argv[0] 8
The strlen of argv[0] 23
The sizeof(vec): 24
The vec.size(): 100
The sizeof(pInt): 8
```

Hat der Compiler Zugriff auf das Array (`sizeof(data)`) dann wird die Größe in Bytes angezeigt. Steht allerdings nur der Zeiger zu Verfügung wie im zweiten Beispiel (`sizeof(argv[0])`) wird die Größe des Zeigers zurück geliefert. Bei einem 32Bit System ist dieser typischerweise 4 Byte groß. Bei einem 64Bit System sind es in der Regel 8 Byte.

Handelt es sich um einen Character String so bietet sich die Funktion `strlen` an, diese Berechnet die Länge anhand der terminierenden `\0`.

Soll hingegen die Anzahl an Elementen im Vector bestimmt werden so ist die Methode `size()` zu benutzen.
