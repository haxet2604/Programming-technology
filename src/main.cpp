#include "Keeper.h"
#include <iostream>

int main()
{
    Keeper keeper;

    int choice;
    do
    {
        std::cout << "Main Menu:\n";
        std::cout << "1. Add Print Edition\n";
        std::cout << "2. Delete Print Edition\n";
        std::cout << "3. Display Print Editions\n";
        std::cout << "4. Save Print Editions to File\n";
        std::cout << "5. Load Print Editions from File\n";
        std::cout << "6. Add Poet\n";
        std::cout << "7. Add Novelist\n";
        std::cout << "8. Add SciFiWriter\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string editionName;
            std::cout << "Enter the name of the Print Edition: ";
            std::cin >> editionName;
            keeper.addPrintEdition(editionName);
            break;
        }
        case 2:
        {
            int indexToDelete;
            std::cout << "Enter the index of the Print Edition to delete: ";
            std::cin >> indexToDelete;
            keeper.deletePrintEdition(indexToDelete);
            break;
        }
        case 3:
        {
            std::cout << "Displaying Print Editions:\n";
            keeper.displayDatabase();
            break;
        }
        case 4:
        {
            std::string filename;
            std::cout << "Enter the filename to save Print Editions: ";
            std::cin >> filename;
            keeper.saveDatabase(filename);
            break;
        }
        case 5:
        {
            std::string filename;
            std::cout << "Enter the filename to load Print Editions: ";
            std::cin >> filename;
            keeper.loadFromFile(filename);
            break;
        }
        case 6:
        {
            int editionIndex;
            std::cout << "Enter the index of the Print Edition to add a Poet: ";
            std::cin >> editionIndex;
            std::string name, years;
            int numMajorWorks;
            std::cout << "Enter poet's name: ";
            std::cin >> name;
            std::cout << "Enter poet's years: ";
            std::cin >> years;
            std::cout << "Enter the number of major works: ";
            std::cin >> numMajorWorks;
            std::string *majorWorks = new std::string[numMajorWorks];
            for (int i = 0; i < numMajorWorks; ++i)
            {
                std::cout << "Enter major work " << i + 1 << ": ";
                std::cin >> majorWorks[i];
            }
            keeper.getPrintEdition(editionIndex)->addPoet(name, years, majorWorks, numMajorWorks);
            delete[] majorWorks;
            break;
        }
        case 7:
        {
            int editionIndex;
            std::cout << "Enter the index of the Print Edition to add a Novelist: ";
            std::cin >> editionIndex;
            std::string name, years, biography;
            int numWorks;
            std::cout << "Enter novelist's name: ";
            std::cin >> name;
            std::cout << "Enter novelist's years: ";
            std::cin >> years;
            std::cout << "Enter number of works: ";
            std::cin >> numWorks;
            std::string *works = new std::string[numWorks];
            for (int i = 0; i < numWorks; ++i)
            {
                std::cout << "Enter work " << i + 1 << ": ";
                std::cin >> works[i];
            }
            std::cout << "Enter novelist's biography: ";
            std::cin >> biography;
            keeper.getPrintEdition(editionIndex)->addNovelist(name, years, works, numWorks, biography);
            delete[] works;
            break;
        }

        case 8: {
            int editionIndex;
            std::cout << "Enter the index of the Print Edition to add a SciFiWriter: ";
            std::cin >> editionIndex;
            std::string name;
            int numWorks;
            bool moviesAdaptation;
            std::cout << "Enter SciFiWriter's name: ";
            std::cin >> name;
            std::cout << "Enter number of works: ";
            std::cin >> numWorks;
            std::string* works = new std::string[numWorks];
            for (int i = 0; i < numWorks; ++i) {
                std::cout << "Enter work " << i + 1 << ": ";
                std::cin >> works[i];
            }
            std::cout << "Does this SciFiWriter have movies adaptation? (1/0): ";
            std::cin >> moviesAdaptation;
            keeper.getPrintEdition(editionIndex)->addSciFiWriter(name, works, numWorks, moviesAdaptation);
            delete[] works;
            break;
        }
        case 9:
        {
            std::cout << "Exiting...\n";
            keeper.~Keeper();
            
            break;
        }
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 9);

    return 0;
}
