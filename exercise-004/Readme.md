# Übungsaufgabe Nr. 4

Bevor Sie mit der Bearbeitung der ersten Übungsaufgabe starten wollen wir zunächst Ihre ``git`` Kenntnisse weiter vertiefen. In den letzten Vorlesung Terminen haben Sie das Konzept der verschiedenen remotes kennengelernt. Dies wollen wir nun vertiefen.

**WICHTIG:** Diese Übungsaufgabe soll einzeln und nicht in Gruppen erfolgen.

## Konfliktfrei

Aller Anfang ist schwer. Um sich das Leben nicht unnötig schwer zu machen sollten Sie den `main` Branch zunächst nicht ändern und jeweils immer nur die Änderungen aus dem allgemeinen Repository pullen. Das klare Ziel am Anfang ist es keine Konflikte zu provozieren.

**ACHTUNG:** Prüfen Sie ob ``origin`` Ihrer Projekt URL entspricht! In dieser darf ``graugans`` nicht auftauchen!

## Anlegen der Branches

Bevor Sie anfangen Quellcode zu schreiben erzeugen sie zunächst eine Kopie des Branches für die erste Übungsaufgabe. Zunächst müssen wir allerdings die lokale Kopie unseres Repository mit `upstream` und Ihrem `origin` synchronisieren.

![image](/doc/exercise-004.gif)

```sh
git fetch --all
git checkout -b solution-004 upstream/main
```

Sie können mit dem Kommando ``git branch -a`` prüfen ob dies erfolgreich war:

```sh
  main
* solution-004
  remotes/origin/HEAD -> origin/main
  remotes/origin/main
  remotes/upstream/main
```

Damit Sie nicht aus versehen in das falsche Repository pushen müssen Sie git mitteilen, dass Sie ab jetzt in Ihren fork pushen wollen:

```sh
git push --set-upstream origin solution-004
```

Nun haben Sie den branch `main` aus meinem Repository in Ihren Fork übertragen.

## Aufgabenstellung

Implementieren Sie eine Klasse zum Umgang mit BMP Dateien. Diese Klasse soll mindestens über die folgenden Methoden verfügen:

```cpp
class BMP {
    bool read(const std::string&  filename);
    bool write(const std::string&  filename);
};
```

Eine detaillierte Beschreibung des BMP Dateiformates finden Sie auf [Wikipedia](https://de.wikipedia.org/wiki/Windows_Bitmap)
Zum Lesen und Schreiben der Daten verwenden Sie die `iostream` Bibliothek aus der standard C++ Library. Ein tutorial hierzu finden Sie unter folgender Webseite: https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm

Erzeugen Sie Sich zuerst eine Struktur für den `BITMAPFILEHEADER` und für den `BITMAPINFOHEADER` verwenden Sie die Integer Datentypen aus dem Header ``cstdint``.

Die zu verarbeitende Datei ist mittels Kommandozeilen Parameter und der Bibliothek ``CLI11`` zu übergeben. Im Debugger können Sie einen Default Wert benutzen.

Implementieren Sie nun die folgenden Funktionen:

- Konvertierung in ein Grauwert-Bild
- Ausgabe des Grauwert Bildes in [Monochromes ASCII-Art](https://de.wikipedia.org/wiki/ASCII-Art#Automatische_Erstellung) und Speicherung in eine Datei
- Implementieren Sie einen [Schwellwertfilter](https://de.wikipedia.org/wiki/Schwellenwertverfahren)

## Zur Kontrolle

Diese Informationen sollte zu Ihrer Datei passen:

```
Hello, ./build/bin/exercise-004!
The filename to use: /workspaces/tea21/build/exercise-004/input.bmp
======= The Bitmap File Info Header =======
  > The start: BM
  > The size in bytes: 43566
  > The offset in bits: 54
======= The Bitmap Info Header =======
  > biSize: 40
  > biWidth: 195
  > biHeight: 74
  > biPlanes: 1
  > biBitCount: 24
  > biCompression: 0
  > biSizeImage: 43512
  > biXPelsPerMeter: 2835
  > biYPelsPerMeter: 2835
  > biClrUsed: 0
  > biClrImportant: 0
```

## Nach getaner Arbeit

Haben Sie alle Punkte erfolgreich abgearbeitet erstellen Sie einen Pull-Request in Ihrem Fork und fügen mich ``graugans`` als Approval hinzu.

## Lernziele

- Vertiefung der git Kenntnisse
- Umgang mit der ``{fmt}`` Bibliothek
- Umgang mit der `CLI11` Bibliothek
- Einlesen und verarbeiten von Dateiformaten
- Einfache Bildverarbeitung
