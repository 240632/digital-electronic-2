# Projekt C : Arcade game - SNAKE

## Členové teamu "Sufurki"

* Gleb Egorov     
* Lukáš Faltys
* Lukáš Jílek
* Tomáš Kopřiva

# Teoretický popis a funkčnost

Náplní tohoto projektu bylo vytvořit arkádovou hru naprogramovanou v jazyce C. V tomto projektu jsme vytvořili starou dobrou známou hru "Snake". 

## Popis hardwaru
### Arduino UNO
Arduino UNO je populární vývojová deska v oblasti elektroniky a programování. Tato deska je založena na mikrokontroléru ATmega328P a poskytuje uživatelům snadný přístup k vytváření interaktivních projektů. Arduino UNO nabízí bohatou sadu digitálních a analogových vstupů a výstupů, což umožňuje propojení s různými senzory a aktuátory. Je ideální pro začátečníky i pokročilé uživatele, kteří chtějí experimentovat s elektronikou a programováním, ať už v oblasti robotiky, IoT nebo jiných kreativních aplikací. Díky otevřenému zdrojovému kódu a rozsáhlé komunitě si získal popularitu jako vývojová platforma pro rychlý a efektivní vývoj elektronických projektů.
![image](https://github.com/240632/digital-electronic-2/assets/124742212/e6df00ce-38f4-4f42-8e67-a39c9064405e)

### OLED I2C DISPLAY 128x64
Displej OLED I2C 128x64 je malý a výkonný displej, který využívá technologii OLED pro vynikající vizuální zobrazení. S integrovaným I2C rozhraním usnadňuje připojení k mikrokontrolérům a snadno umožňuje zobrazování textu, grafiky a informací s vysokým kontrastem a jasnými barvami na rozlišení 128x64 pixelů. Tato komponenta je ideální pro projekty elektroniky, kde je potřeba elegantní a čitelná vizualizace dat.
![image](https://github.com/240632/digital-electronic-2/assets/124742212/8833e9ea-d3e8-459c-9fa1-6a4dffcbd59e)

### Ovládací prvky
Jako ovládací prvky byli použity klasická tlačítka. Tlačítka jsou základními prvky interakce v elektronických zařízeních. Jedná se o malé spínače, které mohou být stisknuty nebo uvolněny, čímž spouští různé funkce.
                                    
![image](https://github.com/240632/digital-electronic-2/assets/124742212/ed933b23-3d57-4d85-a429-439a532490bc)

### Schéma zapojení
![406933259_1738599446563687_7867908720918164180_n](https://github.com/240632/digital-electronic-2/assets/124742212/c7853f52-0dcf-4f0b-ad0a-f986c1017984)


## Popis softwaru

![Snake diagram](https://github.com/240632/digital-electronic-2/assets/124742212/b85febf8-813f-431b-9644-85e8708c318c)



Při začátku cyklu program zkontroluje vektor směru (prvotní směr je do prava). Pokud se nic nezmění (není změčknuté tlačítko), tak se snake pohybuje +1 daným směrem. Pokud během cyklu program zaznamená zmáčknutí tlačítka tak se změní vektor směru +1 (nebo -1) požadovaným směrem. Během jednoho cyklu program také hlídá jestli se snake nedotkne hrany nebo sám sebe, to znamená prohru. Pokud se snake dostane na pozici jablka tak program provede +1 k délce "snejka". Přidaý blok "snejka" se pohybuje za hlavním blokem a kopíruje jeho cestu.Jídlo je generováno random pozicí. 
Pokud během cyklu program zaznamená dotek hrany snakem nebo dotek hlavního bloku snake vedlejšího bloku (snejk se kousne do ocasu), tak je hra ukončena a na display je zobrazena lebka která je předem definována v matici.
Kdyby se hráči povedlo zaplnit celou hrací plochu snakem znamená to výhru a je vygenerován symbol koruny stejným způsobem jako lebka.

Veškeré komentáře k jednotlivým funkcím a příkazům se nachází přímo v programu.

### Odkazy na soubory: 
https://github.com/LukasFaltys/digital-electronics-2/tree/main/snake_V2/DE2_SNAKE


## Instrukce pro použití

Zapojení spočívá v osazení tlačítek vedle sebe, pro představu si je pojmenujme tlačítko 1, tlačítko 2, 3 a 4.
Tlačítko 1: směr vlevo --- 
Tlačítko 2: směr nahoru --- 
Tlačítko 3: směr dolů --- 
Tlačítko 4: směr vpravo --- 
Viz. obrázek (Celý funkčnost potom je zobrazena ve videu)

![image](https://github.com/240632/digital-electronic-2/assets/124742212/008ebd82-aaef-47f8-ae72-f50be94dd445)


## Instruktážní video
https://youtu.be/Zxg_YpIdybA


