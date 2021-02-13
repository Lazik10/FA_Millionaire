#pragma once
#include <string>
#include "QuestionSource.h"
#include "FA_Millionaire.h"

    const int MAX_1k = 10;
    const int MAX_2k = 10;
    const int MAX_3k = 10;
    const int MAX_5k = 14;
    const int MAX_10k = 12;
    const int MAX_20k = 14;
    const int MAX_40k = 14;
    const int MAX_80k = 15;
    const int MAX_160k = 11;
    const int MAX_320k = 10;
    const int MAX_640k = 7;
    const int MAX_1250k = 5;
    const int MAX_2500k = 5;
    const int MAX_5m = 7;
    const int MAX_10m = 5;

    Question questions_1k[MAX_1k]
    {
        // 1000 - 10
        { "Ktere z nasledujicich provedeni nevyrabi firma Vitesco:", "GDI01", "GDI06", "GDI08", "GDI15", "GDI15" },
        { "Kolik linek v CP ma provedeni GEN3:", "Jednu", "Dve", "Tri", "Ctyri", "Jednu" },
        { "Jakou barvu ma karticka oznacujici SCRAP:", "Cervenou", "Modrou", "Zelenou", "Zlutou", "Cervenou" },
        { "Jakou barvu ma karticka oznacujici shodny produkt:", "Cervenou", "Modrou", "Zelenou", "Zlutou", "Zelenou" },
        { "Jakou barvu ma karticka oznacujici vzorky:", "Cervenou", "Modrou", "Zelenou", "Zlutou", "Modrou" },
        { "Cerna viditelna cast na finalni verzi seznoru PS100 se nazyva", "cap", "rap", "sap", "fap", "cap" },
        { "Plast pouzivany v cistem prostoru ma barvu:", "zlutou", "bilou", "cernou", "modrou", "bilou" },
        { "Recal reset kusy po analyze je pred vracenim potreba:", "vypect", "vyscrapovat", "vylestit", "zdegelovat", "vypect" },
        { "Jak se nazyva proces odstranovani gelu ze senzoru:", "degel", "degen", "dezen", "deben", "degel" },
        { "Ktere 2 bondy nahravame k 1 vzorku PS100 do eTransportu:", "S1 a S7", "S2 a S7", "S1 a S11", "S2 a S11", "S2 a S7" },
    };

    Question questions_2k[MAX_2k]
    {
        // 2000 - 10
        { "Jak se nazyva komora k presunu veci mezi CP a BE", "Plynova komora", "Prechodova komora", "Vakuova komora", "Hybernacni komora", "Prechodova komora" },
        { "Co znamena zkratka CP:", "Cisty prostor", "Cerny prostor", "Ciry prostor", "Cenny prostor", "Cisty prostor" },
        { "Kolik elementu ma dual provedeni GEN3:", "Jeden", "Dva", "Tri", "Ctyri", "Dva" },
        { "Co slouzi k prenaseni vice carrieru:", "Magazin", "Casopis", "Noviny", "Email", "Magazin" },
        { "V jakem rozmezi by se mela pohybovat VPTCO hodnota pri uvolnovani GDI:", "-50 az 50", "-45 az 45", "-55 az 55", "-60 az 60", "-50 az 50" },
        { "Ktere pismeno neoznacuje zvlastni znak:", "S", "R", "F", "T", "T" },
        { "Hodnota BIN_Vout_n pri Lot Release u kusu nesmi byt vetsi nez:", "0.505", "0.506", "0.507", "0.508", "0.506" },
        { "Jaky material oznacuje pojem SE147:", "ASIC", "Element", "Gel", "Lepidlo", "Lepidlo" },
        { "Na kolika bondech se odebira konecna SEM pri beznem procesu:", "10k", "30k", "50k", "100k", "50k" },
        { "Jaka barva neoznacuje jednu ze 4 zakladnich smen:", "cervena", "modra", "zelena", "bila", "bila" },
    };

    Question questions_3k[MAX_3k]
    {
        // 3000 - 10
        { "Jake SID musi byt nastaveno pro spravne mereni komunikace u kusu PS100:", "46", "64", "62", "26", "62" },
        { "Jak se nazyva uloziste pro zapis a vyhodnocovani Toolu:", "eTransport", "eReport", "eSport", "eTool", "eTransport" },
        { "Jak se nazyva prostredi pro vyhledavani vyrobenych kusu:", "Evaprod", "Evadrop", "Emaprod", "Evaporod", "Evaprod" },
        { "Jake minimalni CPK musi splnovat OK vysledek v IP:", "1.00", "1.33", "1.66", "2.00", "1.33" },
        { "Ktere z uvedenych se nenachazi na produktu PS100:", "ECA lepidlo", "Bile lepidlo", "Cerne lepidlo", "Gel", "Cerne lepidlo" },
        { "Kolik kusu se vejde do blisteru FA_PS100:", "35", "45", "178", "187", "187" },
        { "Kolik kondenzatoru nalezneme na kusu PS100:", "1", "2", "3", "4", "3" },
        { "Ktera z nasledujicich tabulek neni obsazena v CW v Daily Checku:", "Kusy na retest", "Kusy k analyze", "5Sigma/Outlier", "Archivovane kusy", "Archivovane kusy" },
        { "Teplotni reset kusu na recal by podle navodky mel trvat:", "1h", "0.5h", "1.5h", "2h", "2h" },
        { "Teplotni reset kusu na recal by podle navodky mel byt pri teplote:", "100°C", "110°C", "120°C", "130°C", "120°C" },
    };

    Question questions_5k[MAX_5k]
    {
        // 5000 - 14
        { "Co znamena zkratka FA", "Failure analysis", "Fatal analysis", "Fast analysis", "Further analysis", "Failure analysis" },
        { "Jaky minimalni proud muzeme namerit u OK kusu PS100:", "16.00mA", "16.50mA", "17.00mA", "17.50mA", "17.00mA" },
        { "Jaky maximalni proud muzeme namerit u OK kusu PS100:", "17.00ma", "18.00mA", "19.00mA", "20.00mA", "19.00mA" },
        { "Kolik kusu je potreba k naplneni IP pro PS100:", "100", "150", "200", "250", "200" },
        { "Kolik kusu je potreba k naplneni IP pro GEN3:", "50", "60", "70", "80", "70" },
        { "Jake oznaceni ma blister na BE pro GDI:", "B1", "B2", "B3", "B4", "B3" },
        { "Jake oznaceni ma blister na BE pro DDI:", "B1", "B2", "B3", "B4", "B4" },
        { "Jake oznaceni ma blister na BE pro PS100:", "B1", "B2", "B3", "B4", "B1" },
        { "Ktera data nejsou potreba k uvolneni GEN3 Lotu:", "ASIC die bonding", "Calibration room", "Wirebonding", "Laser marking", "ASIC die bonding" },
        { "Jak se nazyvaji 2 sklenena kolecka pro zamereni elementu:", "Fidusle", "Finusle", "Figusle", "Fimusle", "Fidusle" },
        { "Kolik jednotlivych dratku nalezneme pri otevreni kusu GDI01:", "7", "8", "10", "11", "11" },
        { "Kolik bondu musi udelat WB, aby obondoval spravne cely kus PS100:", "12", "14", "18", "22", "14" },
        { "Jaky prumerny proud by jsme meli namerit u kusu DDI01:", "7mA", "8mA", "8.5mA", "9mA", "8mA" },
        { "Na fotkach z VISCOM aplikace uvidime:", "element", "ASIC", "dratek", "pcb", "element" },
    };

    Question questions_10k[MAX_10k]
    {
        // 10 000 - 12
        { "Jake SID musi byt nastaveno pro spravne vycitani ASIC_ID u kusu PS100:", "63", "36", "83", "38", "38" },
        { "Kolik kondenzatoru nalezneme u provedeni GDI01:", "3", "4", "5", "6", "5" },
        { "Jak se nazyva jev kdy je bond odlepeny od plosky:", "Lift off", "Lift up", "Lift out", "Lift break", "Lift off" },
        { "Dvouslozkove lepidlo ma oznaceni:", "2M", "3M", "4M", "5M", "3M" },
        { "Pro mereni VCC-GND je potreba zapojit na cervenou svorku LCR mustku:", "Cerveny kabel", "Cerny kabel", "Bily kabel", "Zluty kabel", "Cerveny kabel" },
        { "Pro mereni GND-Vout je potreba zapojit jake kabely na svorky LCR mustku:", "Cerveny a cerny", "Cerny a bily", "Bily a zluty", "Cerveny a bily", "Cerny a bily" },
        { "Jaka je sirka bondovaciho dratku:", "36", "38", "46", "48", "38" },
        { "Jakou barvu ma Lot Traveler pro projekt GDI01:", "Zelenou", "Modrou", "Cervenou", "Zlutou", "Zelenou" },
        { "Jakou barvu ma Lot Traveler pro projekt DDI05:", "Zelenou", "Modrou", "Cervenou", "Zlutou", "Cervenou" },
        { "Jakou barvu ma Lot Traveler pro projekt GDI06:", "Sedou", "Ruzovou", "Oranzovou", "Zlutou", "Ruzovou" },
        { "Kolik fotek z IR je potreba zkontrolovat pri nalezu voidu u PS100", "100", "120", "200", "80", "120" },
        { "Maximalni velikost diry ve svaru muze byt:", "1mm", "0,5mm", "zadna", "0.1mm", "zadna" },
    };

    Question questions_20k[MAX_20k]
    {
        // 20 000 - 14
        { "Jakou barvu ma Lot Traveler pro projekt GDI02:", "Zelenou", "Modrou", "Cervenou", "Zlutou", "Modrou" },
        { "Jakou barvu ma Lot Traveler pro projekt GDI03:", "Zelenou", "Modrou", "Cervenou", "Zlutou", "Zlutou" },
        { "Jakou barvu ma Lot Traveler pro projekt GDI07:", "Sedou", "Ruzovou", "Oranzovou", "Zlutou", "Oranzovou" },
        { "Jakou barvu ma Lot Traveler pro projekt GDI08:", "Sedou", "Ruzovou", "Oranzovou", "Zlutou", "Sedou" },
        { "Jakou barvu ma Lot Traveler pro projekt DDI01:", "Fialovou", "Hnedou", "Modrou", "Ruzovou", "Fialovou" },
        { "Jakou barvu ma Lot Traveler pro projekt DDI07:", "Zelenou", "Modrou", "Cervenou", "Zlutou", "Modrou" },
        { "Pri blokaci ke sber. bodu se pouziva jake cislo duvodu pohybu:", "6009", "9006", "6008", "8006", "6009" },
        { "Kolik procent kusu z denni vyroby by melo byt vybrano do IP:", "1%", "2%", "3%", "5%", "2%" },
        { "Maximalni sirka wedge muze byt kolikrat vetsi nez sirka dratku", "1.5x", "2x", "2.5", "3x", "2x" },
        { "Jake ciselne oznaceni nalezneme na PCB pro GDI02:", "400", "500", "600", "700", "400" },
        { "Jake ciselne oznaceni nalezneme na PCB pro GDI01:", "400", "500", "600", "700", "500" },
        { "Kolik cisel nasleduje za znakem T v oznaceni toolu:", "6", "7", "8", "9", "8" },
        { "Kolik teplotnich grafu uvidime v IP u GDI01:", "6", "7", "8", "9", "6" },
        { "Kolik teplotnich grafu uvidime v IP u DDI05:", "6", "7", "8", "9", "9" },
    };
    
    Question questions_40k[MAX_40k]
    {
        // 40 000 - 14
        { "Jake ciselne oznaceni ma operace Calibration Room u PS100:", "0462", "0464", "0466", "0460", "0462" },
        { "Jake ciselne oznaceni ma operace Calibration Mid u PS100:", "0462", "0464", "0466", "0460", "0464" },
        { "Jake ciselne oznaceni ma operace Calibration Hot u PS100:", "0462", "0464", "0466", "0460", "466" },
        { "Jake ciselne oznaceni ma operace Drift Test u PS100:", "0476", "0467", "0464", "0446", "0476" },
        { "Jake ciselne oznaceni ma operace Bin A u PS100:", "0490", "0491", "0492", "0493", "0490" },
        { "Jake ciselne oznaceni ma operace Bin B u PS100:", "0495", "0496", "0494", "0497", "0495" },
        { "Jake ciselne oznaceni ma operace Laser Marking u PS100:", "0520", "0530", "0540", "0550", "0530" },
        { "Jake ciselne oznaceni ma operace MOI Final Inspection u PS100:", "0575", "0574", "0577", "0576", "0575" },
        { "Jak èasto by se melo opakovat školení zamìstnancù o požární ochranì?", "1 za rok", "2 za rok", "3 za rok", "1 za 2 roky", "1 za 2 roky" },
        { "Dvouslozkove lepidlo ma v nazvu:", "Scotch-Weld", "Scotch-Wield", "Snotch-Weld", "Snotch-Wield", "Scotch-Weld" },
        { "Kolik kHz je potreba nastavit pro mereni kapacity Vout-GND u GDI01:", "10kHz", "72KHz", "75kHz", "100kHz", "100kHz" },
        { "Kolik kHz je potreba nastavit pro mereni kapacity Vout-GND u DDI01:", "10kHz", "72KHz", "75kHz", "100kHz", "72kHz" },
        { "Hodnota kontaktniho voidu mezi void pady nesmi byt vetsi nez:", "120", "140", "100", "160", "160" },
        { "Jake je maximalni priblizeni SEM mikroskopu:", "100000x", "105000x", "110000x", "150000x", "105000x" },
    };

    Question questions_80k[MAX_80k]
    {
        // 80 000 - 15
        { "Jake A2C ma projekt GDI01 final:", "A2C89864801", "A2C98279501", "A2C11457400", "A2C93096601", "A2C89864801" },
        { "Jake A2C ma projekt GDI02 final:", "A2C89864801", "A2C98279501", "A2C11457400", "A2C93096601", "A2C93096601" },
        { "Jake A2C ma projekt GDI06 final:", "A2C89864801", "A2C98279501", "A2C11457400", "A2C93096601", "A2C98279501" },
        { "Jake A2C ma projekt GDI08 final:", "A2C86412000", "A2C89864801", "A2C11457400", "A2C97839400", "A2C11457400" },
        { "Jake A2C ma projekt DDI01 final:", "A2C97839400", "A2C90375501", "A2C97737801", "A2C97737800", "A2C90375501" },
        { "Jake A2C ma projekt DDI05 final:", "A2C97839400", "A2C90375501", "A2C97737801", "A2C97737800", "A2C97839400" },
        { "Jake A2C ma projekt PS100 final:", "A2C86412000", "A2C87412000", "A2C85412000", "A2C81412000", "A2C86412000" },
        { "Pri blokaci ke sber. bodu pro FA LAB je oznaceni skladu:", "P792", "P797", "P798", "P791", "P792" },
        { "Minimalni sirka wedge musi byt kolikrat vetsi nez sirka dratku", "1.1x", "1.2x", "1.3x", "1.4x", "1.2x" },
        {" Jakou minimalni kapacitu GND-CASE muzeme namerit u OK Dual GEN3 kusu:", "234nF", "224nF", "244nF", "254nF", "234nF" },
        {" Jakou minimalni kapacitu Vout-GND muzeme namerit u OK Single GEN3 kusu:", "170nF", "180nF", "160nF", "190nF", "180nF" },
        { "Jakou barvu ma stitek u klicu k leve skrini GEN3 s archivem:", "Zelenou", "Cervenou", "Cernou", "Modrou", "Zelenou" },
        { "Jakou maximalni prodlevu by melo mit oznameni reportu vedoucimu vyroby:", "1h", "2h", "3h", "4h", "3h" },
        { "Protokol k IP (data v excelu) nalezneme ulozena na siti ve slozce:", "didm0542", "didm0541", "didm0545", "didm0554", "didm0542" },
        { "Fotky z VISCOM aplikace se ukladaji na siti ve slozce:", "didm0542", "didm0541", "didm0545", "didm054", "didm0542" },
    };

    Question questions_160k[MAX_160k]
    {
        // 160 000 - 11
        { "Jakou hodnotu sily (N) musel presahovat test konektoru GDI01:", "100", "110", "120", "130", "110" },
        { "Jakou hodnotu sily (N) musel presahovat test konektoru GDI06:", "100", "110", "120", "130", "110" },
        { "Jakou maximalni kapacitu GND-CASE muzeme namerit u OK Single GEN3 kusu:", "271nF", "281nF", "291nF", "301nF", "271nF" },
        { "Jakou maximalni kapacitu VCC-GND muzeme namerit u OK Dual GEN3 kusu:", "1010nF", "1011nF", "1012nF", "1013nF", "1012nF" },
        { "Jakou minimalni kapacitu VCC-GND muzeme namerit u OK Single GEN3 kusu:", "450nF", "455nF", "457nF", "453nF", "457nF" },
        { "Jake A2C ma projekt DDI07 final:", "A2C11457400", "A2C98279501", "A2C38882700", "A2C93096601", "A2C38882700" },
        { "Jakou minimalni kapacitu VCC-CASE muzeme namerit u OK Single GEN3 kusu:", "271nF", "261nF", "281nF", "291nF", "271nF" },
        { "Jakou minimalni kapacitu GND-CASE muzeme namerit u OK Single GEN3 kusu:", "221nF", "211nF", "201nF", "231nF", "221nF" },
        { "Jakou minimalni kapacitu VCC-GND muzeme namerit u OK Dual GEN3 kusu:", "748nF", "728nF", "738nF", "718nF", "748nF" },
        { "Jakou minimalni kapacitu VCC-CASE muzeme namerit u OK Dual GEN3 kusu:", "279nF", "289nF", "299nF", "269nF", "279nF" },
        { "Jak se nazyva vyrobce stitkovacky v FA Lab:", "Dymo", "Dito", "Demo", "Deno", "Dymo" },
    };

    Question questions_320k[MAX_320k]
    {
        // 320 000 - 10
        {"Jakou maximalni kapacitu VCC-GND muzeme namerit u OK Single GEN3 kusu:", "539nF", "549nF", "559nF", "529nF", "559nF" },
        { "Dratek cislo 7 u PS100 ma oznaceni", "vn", "sp", "vp", "sn", "vn" },
        { "Dratek cislo 8 u PS100 ma oznaceni", "vn", "sp", "vp", "sn", "sn" },
        { "Jakou hodnotu sily (N) musel presahovat test konektoru GDI02:", "300", "350", "250", "200", "300" },
        { "Jakou hodnotu sily (N) musel presahovat test konektoru GDI03:", "300", "350", "250", "200", "300" },
        { "Jakou maximalni kapacitu VCC-CASE muzeme namerit u OK Dual GEN3 kusu:", "341nF", "346nF", "351nF", "356nF", "341nF" },
        { "Jakou maximalni kapacitu GND-CASE muzeme namerit u OK Dual GEN3 kusu:", "286nF", "268nF", "278nF", "287nF", "286nF" },
        { "Jak se nazyvaji trohuhelnicky na okraji elementu", "Tie bars", "Die bars", "Tri bars", "Pie bars", "Tie bars" },
        { "Jaky obsah ma M3 lepidlo:", "45mL", "50mL", "55mL", "60mL", "45mL" },
        { "Jak dlouho trva SEMce poridit snimek pri rozliseni 2048 a kvalite best:", "25s", "27s", "28s", "30s", "28s" },
    };
    Question questions_640k[10]
    {
        // 640 000 - 7
        { "Dratek cislo 5 u PS100 ma oznaceni", "vn", "sp", "vp", "sn", "vp" },
        { "Dratek cislo 6 u PS100 ma oznaceni", "vn", "sp", "vp", "sn", "sp" },
        { "Jakou maximalni kapacitu Vout-GND muzeme namerit u OK Single GEN3 kusu:", "220nF", "240nF", "230nF", "250nF", "220nF" },
        { "Jakou maximalni kapacitu VCC-CASE muzeme namerit u OK Single GEN3 kusu:", "301nNF", "311nF", "321nF", "331nF", "331nF" },
        { "Oznaceni klasifikace nebezpecneho horlaveho odpadu je:", "HP3", "HP4", "HP5", "HP6", "HP3" },
        { "Oznaceni klasifikace nebezpecneho ziraveho odpadu je:", "HP3", "HP4", "HP5", "HP6", "HP4" },
        { "Oznaceni klasifikace nebezpecneho ekotoxickeho odpadu je:", "HP20", "HP14", "HP16", "HP18", "HP14" },
    };

    Question questions_1250k[MAX_1250k]
    {
        // 1 250 000 - 5
        { "Kterou H vetu nenalezneme na stitku Acetonu:", "H225", "H319", "H336", "H207", "H207" },
        { "Kterou H vetu nalezneme na stitku Impasolu:", "H113", "H338", "H226", "H405", "H226" },
        { "Kolik procent bylo udeleno FA lab pri 5S auditu v breznu 2020:", "95", "96", "97", "98", "95" },
        { "Drsnost plochy portu je v PA oznacena jako zkouska cislo:", "120", "121", "122", "123", "122" },
        { "Jaka je ciselna zkratka pro uvolneni ze SAP blokace:", "TT 56741", "TT 56841", "TT 56742", "TT56842", "TT 56741" },
    };

    Question questions_2500k[MAX_2500k]
    {
        // 2 500 000 - 5
        { "Kolik se nejvice uvolnilo kusu v jednom lotu PS100 v roce 2020:", "25400", "25500", "25450", "25500", "25400" },
        { "Ktery den byl uvolnen prvni lot PS100 v roce 2020:", "4.1.", "5.1", "6.1", "7.1", "7.1" },
        { "Ktery den byl uvolnen prvni lot GEN3 v roce 2020:", "3.1.", "4.1", "6.1", "5.1", "3.1" },
        { "OK zavitove meridlo pro DDI ma oznaceni:", "Jg-136-T", "Jg-139-T", "Jg-136-R", "Jg-139-R", "Jg-136-T" },
        { "OK zavitove meridlo pro GDI ma oznaceni:", "Jg-138-T", "Jg-135-T", "Jg-136-T", "Jg-137-T", "Jg-138-T" },
    };

    Question questions_5m[MAX_5m]
    {
        // 5 000 000 - 7
        { "Podle jakeho navodu se vystavuje QRQC:", "CAP1012682_F05", "CAP1013682_FA05", "CAP1012682_F06", "CAP1013682_F06", "CAP1012682_F05" },
        { "Navodka pro vycitani ASIC_ID ma oznaceni:", "SA_PN_0_98127_C_AA", "SA_PN_1_98127_C_AB", "SA_PN_0_98127_C_AB", "SA_PN_1_98127_C_AA", "SA_PN_0_98127_C_AA" },
        { "Dokument Postup Produkt auditu ma oznaceni:", "SA_PN_0_98070_C", "SA_PN_1_98070_C", "SA_PN_0_98060_C", "SA_PN_1_98060_C", "SA_PN_0_98070_C" },
        { "Kolik kritickych kusu PS100 bylo zapsano do kriticke tabulky za rok 2019:", "9319", "9562", "9485", "9641", "9319" },
        { "Kolik kritickych kusu GEN3 bylo zapsano do kriticke tabulky za rok 2019:", "946", "975", "931", "953", "946" },
        { "NOK zavitove meridlo pro DDI ma oznaceni:", "Jg-137-T", "Jg-136-T", "Jg-136-R", "Jg-137-R", "Jg-137-T" },
        { "NOK zavitove meridlo pro GDI ma oznaceni:", "Jg-139-T", "Jg-136-T", "Jg-139-R", "Jg-136-R", "Jg-139-T" },
    };

    Question questions_10m[MAX_10m]
    {
        // 10 000 000 - 5
        { "Kolik kritickych kusu s chybou RAMP_OSPI_Communication bylo zapsano v tabulce za rok 2019:", "2110", "2111", "2010", "2011", "2110" },
        { "Kolik se nejvice uvolnilo kusu v jednom lotu PS100 v roce 2020:", "25912", "25914", "25910", "25908", "25912" },
        { "Vykres dokumentace GDI02 v PA pro MCP ma oznaceni:", "40696397_DRW_000_AE", "40669397_DRW_000_AE", "40696937_DRW_000_AE", "40696379_DRW_000_AE", "40696397_DRW_000_AE" },
        { "Blokace 000589 u PS100 byla na:", "Bent wire", "Delaminace na PCB", "Short wire", "Heelbreak", "Bent wire" },
        { "Šrotaèní protokol TRU_5212_20_037 byl kvuli:", "ukonceni vyroby", "vypadku proudu", "krivym dratkum", "chybejicim datum z CP", "krivym dratkum" },
    };

    Question QuestionSource::GetQuestion()
    {
        Question question_selected;

        switch (FAMillionaire::FA_Millionaire::GetRound())
        {
        case 0:
            question_selected = questions_1k[rand() % MAX_1k];
            break;
        case 1:
            question_selected = questions_2k[rand() % MAX_2k];
            break;
        case 2:
            question_selected = questions_3k[rand() % MAX_3k];
            break;
        case 3:
            question_selected = questions_5k[rand() % MAX_5k];
            break;
        case 4:
            question_selected = questions_10k[rand() % MAX_10k];
            break;
        case 5:
            question_selected = questions_20k[rand() % MAX_20k];
            break;
        case 6:
            question_selected = questions_40k[rand() % MAX_40k];
            break;
        case 7:
            question_selected = questions_80k[rand() % MAX_80k];
            break;
        case 8:
            question_selected = questions_160k[rand() % MAX_160k];
            break;
        case 9:
            question_selected = questions_320k[rand() % MAX_320k];
            break;
        case 10:
            question_selected = questions_640k[rand() % MAX_640k];
            break;
        case 11:
            question_selected = questions_1250k[rand() % MAX_1250k];
            break;
        case 12:
            question_selected = questions_2500k[rand() % MAX_2500k];
            break;
        case 13:
            question_selected = questions_5m[rand() % MAX_5m];
            break;
        case 14:
            question_selected = questions_10m[rand() % MAX_10m];
            break;
        default:
            break;
        };

        return question_selected;
    }

