#include <iostream>
#include "keeper.h"

int main()
{
    Keeper keeper;

    int choice;
    std::string name, years, biography;
    bool moviesAdaptation;
    std::string *works;
    int numWorks;

    std::string saveFilename = ""; // Initialize variables outside the switch block
    std::string loadFilename = "";

    do
    {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Добавить печатное издание" << std::endl;
        std::cout << "2. Удалить печатное издание" << std::endl;
        std::cout << "3. Сохранить базу данных" << std::endl;
        std::cout << "4. Загрузить базу данных" << std::endl;
        std::cout << "5. Вывести базу данных" << std::endl;
        std::cout << "6. Выйти" << std::endl;
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        std::cin.ignore();

        switch (choice)
        {
        case 1:
        {
            std::string peName;
            std::cout << "Введите имя печатного издания: ";
            std::cin.ignore();
            std::getline(std::cin, peName);

            PrintEdition printEdition = PrintEdition(peName);
            keeper.addPrintEdition(printEdition);

            break;
        }

        case 2:
            std::cout << "Введите индекс печатного издания для удаления: ";
            int index;
            std::cin >> index;
            keeper.deletePrintEdition(index);
            break;

        case 3:
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> saveFilename;
            keeper.saveDatabase(saveFilename);
            break;

        case 4:
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> loadFilename;
            keeper.saveDatabase(loadFilename);
            break;
        case 5:
            keeper.displayDatabase();
            break;
        case 6:
            std::cout << "Завершение программы." << std::endl;
            break;
        default:
            std::cout << "Некорректный выбор. Пожалуйста, попробуйте снова." << std::endl;
        }

        std::cout << std::endl;

    } while (choice != 6);

    return 0;
}
