# Integer-Hash-Tabelle

Implementation einer einfachen Hash-Tabelle in C, die Ganzzahlen (int) als Schlüssel und Werte speichert.

Wichtige Merkmale:
Separate Verkettung: Kollisionen werden durch verkettete Listen behandelt.
Hashfunktion: key % size, immer positiv.

Operationen:
insert: Fügt ein (key, value)-Paar ein oder überschreibt.
get: Gibt den Wert zu einem Schlüssel zurück oder -1.
remove_key: Entfernt einen Schlüssel, Rückgabe true/false.

Datenstruktur: Array von Pair*-Listen.


# Hash-Tabelle mit Strings

Erweiterung der Hash-Tabelle, sodass Strings (const char*) als Schlüssel unterstützt wurden.

Wichtige Unterschiede Integer-Hash-Tabelle:
Schlüsseltyp: const char* statt int.
Hashfunktion: hash_string(str, size) – erzeugt positive Hashes für Strings.
Vergleich: mit strcmp, nicht mit ==.
Speicherung: Schlüssel werden mit strdup kopiert.

Operationen:
insert, get, remove, analog zu Integer-Hash-Tabelle, aber mit String-Schlüsseln.

Zusätzliche Datei:
utils.c mit hash_string und strdup.
