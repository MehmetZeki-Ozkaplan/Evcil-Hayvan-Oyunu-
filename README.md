# Pet Raising Game

This program is a simple program that I wrote in the C programming language during the 2022-2023 1st grade Computer Engineering Education period.

This program allows users to manage their virtual pets. Users can manage the types, names, energy levels, happiness levels and emotional states of their pets.

# Pet Nurturing Game

Pet Nurturing Game is a text-based pet care game written in C. This game allows users to add, update, and interact with their virtual pets. The pets' statuses are updated based on user interactions.

## Contents

- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Function Documentation](#function-documentation)
- [Contributors](#contributors)
- [License](#license)

## Introduction

Pet Nurturing Game is a simple yet engaging program where users can manage their virtual pets. Users can feed, water, play with, and perform other activities with their pets. This game provides a good opportunity for practicing basic C programming and file handling.

## Features

- Add new pets.
- Update existing pet information.
- Feed and water pets.
- Play with and clean pets.
- Pet them and reward them.
- List pets and save their data to a file.

## Project Structure
├── main.c            // Entry point of the program
├── interface.h       // Header file with function declarations
├── implementation.c  // File containing the game's functionality
├── evcil_veri.txt    // Data file storing pet information
└── evcil_cikti.txt   // Output file recording the current pet statuses

## Installation

To compile and run Pet Nurturing Game, follow these steps:

- Clone the Repository :

      git clone https://github.com/username/project-name.git

      cd project-name

- Compile the Code:

      gcc -o pet_game main.c implementation.c

- Run the Executable:

      ./pet_game

## Usage

When the program runs, it displays a menu offering various options to the user. An example of the screen output is as follows:

    -----EVCİL HAYVAN YETİŞTİRME OYUNU-----
    |1. Evcil Hayvanınızı Ekleyin         |
    |2. Evcil hayvanınızı Güncelleyin     |
    |3. Evcil Hayvan Verinizi Silin        |
    |4. Evcil Hayvanlarınızı Listeleyin   |
    |5. Evcil Hayvanınıza Yemek Verin      |
    |6. Evcil Hayvanınıza Su Verin        |
    |7. Evcil Hayvanınız ile Oyun Oynayın |
    |8. Evcil Hayvanınızı Temizleyin      |
    |9. Evcil Hayvanınızı Sevin           |
    |10. Evcil Hayvanınızı Uyutun         |
    |11. Evcil Hayvanınızı Ödüllendirin   |
    |12. İşlemleri Kaydet ve Çıkış        |
    ______________________________________
    Seçmek istediğiniz işlem numarasını giriniz: 

Users can interact with their pets by selecting various options. Example interactions and their outputs:

- Example 1: Adding a Pet :

      Seçmek istediğiniz işlem numarasını giriniz: 1
      Tür: Kedi
      Ad: Pamuk
      Evcil hayvan başarıyla eklendi!

- Example 2: Listing Pets :

      Seçmek istediğiniz işlem numarasını giriniz: 4
      1. Kedi, Pamuk, Enerji: 60, Mutluluk: 60, Duygu: Mutlu

- Example 3: Feeding a Pet :
  
      Seçmek istediğiniz işlem numarasını giriniz: 5
      Hangi hayvana yemek vermek istersiniz? (Ad): Pamuk
      Pamuk'a yemek verildi!

- Example 4: Cleaning a Pet :

      Seçmek istediğiniz işlem numarasını giriniz: 8
      Hangi hayvanı temizlemek istersiniz? (Ad): Pamuk
      Pamuk temizlendi!

## Function Documentation
main.c

The main program file calls menu() and dosyadanOku() to greet the user and display the menu.
interface.h

Function declarations:

    void dosyadanOku();
    void menu();
    void dosyayaKaydet();
    void duyguGuncelle();
    void hayvanaYemekVer();
    void hayvaniOyunOynat();
    void hayvaniTemizle();
    void hayvaniSev();
    void hayvaniUyut();
    void hayvaniOdullendir();
    void hayvanaSuVer();
    void hayvaniGuncelle();

implementation.c:
Functions to process and update pet information. For detailed explanations and functionalities, refer to the file content.

## Contributors:
Names of everyone who contributed to this project can be listed here. Those interested in contributing can refer to the contributing guide for pull requests and suggestions.

## License:
This project is licensed under the MIT License. For details, see the License file.

