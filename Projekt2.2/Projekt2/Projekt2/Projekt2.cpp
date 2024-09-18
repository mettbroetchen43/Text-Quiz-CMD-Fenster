#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // Für rand() und srand()
#include <ctime>   // Für time
#include <windows.h> // Für system("pause")

// Funktion zum Erzeugen einer zufälligen Variation des Textes
std::string zufaelligeVariation(const std::string& text) {
    std::string variation = text;

    // Zufällig Buchstaben ersetzen
    for (char& c : variation) {
        if (std::rand() % 3 == 0) { // 1/3 Wahrscheinlichkeit
            c = 'a' + std::rand() % 26; // Ersetzt durch einen zufälligen Buchstaben
        }
    }

    return variation;
}

// Funktion zur Überprüfung der Matheaufgaben
void pruefeMatheAufgabe(int richtigeAntwort, int benutzerAntwort) {
    if (benutzerAntwort == richtigeAntwort) {
        std::cout << "Richtig!" << std::endl;
    }
    else {
        std::cout << "Leider falsch. Die richtige Antwort ist " << richtigeAntwort << "." << std::endl;
    }
}

// Funktion zur Anzeige von Aufgaben
void aufgabenAnzeigen() {
    int antwort;
    std::string benutzereingabe;

    // Allgemeine Quizfragen
    std::vector<std::pair<std::string, std::string>> quizfragen = {
        {"Was ist die Hauptstadt von Deutschland?", "Berlin"},
        {"Welcher Planet ist der vierte von der Sonne?", "Mars"},
        {"Wie viele Bundesländer hat Deutschland?", "16"},
        {"Wer malte die Mona Lisa?", "Leonardo da Vinci"},
        {"Was ist die chemische Formel von Wasser?", "H2O"}
    };

    std::cout << "\nAllgemeine Quizfragen:\n";
    for (const auto& frageAntwort : quizfragen) {
        std::cout << frageAntwort.first << std::endl;
        std::getline(std::cin, benutzereingabe);
        if (benutzereingabe == frageAntwort.second) {
            std::cout << "Richtig!" << std::endl;
        }
        else {
            std::cout << "Leider falsch. Die richtige Antwort ist: " << frageAntwort.second << "." << std::endl;
        }
    }

    // Deutsch-Textverständnis Fragen
    std::cout << "\nDeutsch-Textverständnis Fragen:\n";
    std::vector<std::pair<std::string, std::string>> textVerstaendnis = {
        {"Was ist das Hauptthema des Textes 'Der Froschkönig'?", "Ein Frosch wird zum Prinzen"},
        {"In welchem Jahr wurde die erste deutsche Rechtschreibung eingeführt?", "1901"},
        {"Wer schrieb 'Faust'?", "Goethe"},
        {"Was ist ein Synonym für 'schnell'?", "rasch"},
        {"Was bedeutet 'Metapher'?", "Bildhafte Sprache"}
    };

    for (const auto& frageAntwort : textVerstaendnis) {
        std::cout << frageAntwort.first << std::endl;
        std::getline(std::cin, benutzereingabe);
        if (benutzereingabe == frageAntwort.second) {
            std::cout << "Richtig!" << std::endl;
        }
        else {
            std::cout << "Leider falsch. Die richtige Antwort ist: " << frageAntwort.second << "." << std::endl;
        }
    }

    // Matheaufgaben
    std::cout << "\nMatheaufgaben:\n";
    for (int i = 1; i <= 5; ++i) {
        int zahl1 = std::rand() % 10 + 1;
        int zahl2 = std::rand() % 10 + 1;
        int richtigeAntwort = zahl1 + zahl2;
        std::cout << "Aufgabe " << i << ": Was ist " << zahl1 << " + " << zahl2 << "?" << std::endl;
        std::cin >> antwort;
        std::cin.ignore(); // Eingabepuffer leeren
        pruefeMatheAufgabe(richtigeAntwort, antwort);
    }
}

int main() {
    std::string text;
    std::vector<std::string> zufaelligeTexte;

    // Zufallsgenerator initialisieren
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Text eingeben
    std::cout << "Geben Sie ein Wort ein: ";
    std::getline(std::cin, text);

    // Generiere 10 zufällige Variationen des Textes
    for (int i = 0; i < 10; ++i) {
        zufaelligeTexte.push_back(zufaelligeVariation(text));
    }

    // Ausgabe der zufälligen Texte
    std::cout << "\nZufällige Variationen des Textes:\n";
    for (const auto& eintrag : zufaelligeTexte) {
        std::cout << eintrag << std::endl;
    }

    // Aufgaben anzeigen
    aufgabenAnzeigen();

    // Programm hält die Konsole offen
    std::cout << "\nDrücken Sie eine beliebige Taste, um das Programm zu beenden..." << std::endl;
    system("pause"); // Warten auf Tasteneingabe

    // Hier wird das Fehlerfenster erst nach dem Schliessen des Cmd-Fensters angezeigt:
    MessageBox(NULL, L"Wennde lachsch, kriegsch nachher eine, he, i sag's dir!", L"Wichtige naricht", MB_ICONERROR | MB_OK);

    return 0;
}