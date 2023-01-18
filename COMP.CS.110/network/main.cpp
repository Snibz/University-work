#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

/*
Veikko Verkostomarkkinoijalla on ongelma (verkostomarkkinoinnin lisäksi).
Verkostomarkkinointiverkoston idea on, että jokainen markkinoija on värvännyt mukaan markkinointiin uusia henkilöitä.
Missään ei kuitenkaan ole tallella tietoa koko markkinointiverkoston rakenteesta.
Tiedossa on vain kuka markkinoijista on värvännyt ketäkin muita markkinointiin mukaan.
Auta Veikkoa selvittämään verkoston rakenne kirjoittamalla ohjelma, joka tulostaa verkoston rakenteen puumaisena kuviona ja osaa myös laskea aliverkostojen syvyyksiä ja kokoja.

Ohjelmakoodipohjassa on valmiina toteutettu pääohjelma, joka lukee ja jäsentelee käyttäjän syötteet.
Jos muutat komentotulkin ohjelmakoodia, pidä huolta, että se toimii samalla tavoin kuin alkuperäinen komentotulkki.

Tehtävänä on valita sopiva tietorakenne tietojen tallentamiseen ja toteuttaa komentojen toiminta seuraavasti:

    S (eli store, tallenna) saa parametrinaan kahden henkilön tunnisteet (esim. nimet tai id-numerot tms), jotka ovat merkkijonoja. Ensimmäisenä on sen henkilön tunniste, joka on värvännyt mukaan markkinointiin henkilön, jolla on toisena oleva tunniste. Eli toisin sanottuna ensimmäiseksi mainittu henkilö on verkostossa ylempänä kuin toiseksi mainittu henkilö. Kukin henkilö voi olla värvännyt mukaan kuinka monta henkilöä tahansa. Tässä tehtävässä voit olettaa, että henkilöiden tunnisteet eivät muodosta silmukoita, eli alempana oleva tunniste ei koskaan ole mitään kautta värvääjäänsä ylempänä.
    P (eli print, tulosta) saa parametrinaan yhden tunnisteen. Ohjelma tulostaa sen henkilön aliverkoston, jonka tunniste on kyseessä. Ensimmäiseksi tulostetaan kysytyn henkilön tunniste. Hänen alapuolelleen 2 pistemerkillä sisennettynä tulostetaan niiden henkilöiden tunnisteet, jotka hän on värvännyt mukaan markkinointiin ja heidän alapuolelleen samalla tavoin enemmän sisennettynä heidän värväämänsä henkilöt. Henkilöt tulostetaan siinä järjestyksessä, missä heidät on kirjattu värvätyiksi. Jos henkilölle ei ole kirjattu värvättyjä tai henkilöä ei ole kirjattu ollenkaan, tulostetaan vain hänen tunnisteensa.
    C (eli count, lukumäärä) saa parametrinaan yhden tunnisteen. Ohjelma tulostaa kyseisen henkilön aliverkoston suuruuden, eli toisin sanoen hänen värväämiensä henkilöiden muodostaman aliverkon jäsenten määrän.
    D (eli depth, syvyys) saa parametrinaan yhden tunnisteen. Ohjelma tulostaa annetun henkilön aliverkon syvyyden, eli toisin sanoen pisimmän värväysketjun pituuden hänestä lähtien.

*/

const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


int depth_command(const std::map<std::string, std::vector<std::string>> network,
                  const std::string id1, int rec_chain_depth)
{
    // At this point, the chain depth is at least 2, since this function is called only if id1
    // is a key in the map, so they must have recruited someone, if they were the "first recursion".
    int max_depth = rec_chain_depth;

    for ( auto& id2 : network.at(id1) ) {
        // for each element in id1 vector, we must check if it is a key in vector.
        // If it is, we increase rec_chain_depth by 1 and recurse.

        if ( network.find(id2) != network.end() ) {
            // id2 is a key in network, they have recruited.
            //
            int max_here = depth_command(network, id2, rec_chain_depth + 1);
            if ( max_here > max_depth ) {
                max_depth = max_here;
            }
        } else {
            // id2 is not a key, so depth cannot further increase from that chain.
            continue;
        }
    }
    return max_depth;
}

int count_command(const std::map<std::string, std::vector<std::string>> network,
                  const std::string id1)
{
    // Recursively determines the amount of people under the person id1,
    // and returns that integer.

    // id1 has himself recruited this many names. For each of these names,
    // we'll have to check if they are in network.
    // if they are, we'll recursively count the amount they have recruited, and so on.
    std::vector<std::string>::size_type personally_recruited = network.at(id1).size();
    int recruited_by_causality = personally_recruited;

    for ( auto& id2 : network.at(id1) ) {

        if ( network.find(id2) != network.end() ) {
            // id2 is in network, so they have recruited, so we recurse
            int count = count_command(network, id2);
            recruited_by_causality += count;
        } else {
            // id2 not in network, so they haven't recruited, so we continue
            continue;
        }

    }
    return recruited_by_causality;
}




int print_command(const std::map<std::string, std::vector<std::string>> network,
                   const std::string id1, int recursion_counter=0)
{
    // Recursively prints the values of the vector attached to the key
    // id1 of the map network. If the element in the vector is a key itself,
    // it's vector's elements are also printed, hence the recursion.


    for ( auto& id2 : network.at(id1) ) {
        // id2 is a name in vector of id1
        for ( int i=0; i<recursion_counter;++i) {
            std::cout << "..";
        }
        std::cout << ".." << id2 << std::endl;

        // to check if id2 is a key in network or no.
        // if it is, we do recursion. If not, we continue
        if ( network.find(id2) != network.end() ) {
            // id2 is a key, which mean it has further id's.
            // do recursion.
            print_command(network, id2, recursion_counter + 1);
        } else {
            // id2 is not a key, so we do not recurse.
            // all that needs doing is done so we return backward.
            continue;
        }
    }
return 0;
}


std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

int main()
{
    // TODO: Implement the datastructure here

    std::map<std::string, std::vector<std::string>> network;

    while(true)
    {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        std::string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            // TODO: Implement the command here!
            // Key is id1, id2 is a name added to the vector that is the value
            // accessed by id1.
            // Two options, either the name already in map or not.
            // We handle each path.
            if ( network.find(id1) != network.end() ) {
                // Name already in the map, thus it has a vector
                network.at(id1).push_back(id2);
            } else {
                // Name not in map, so it does not have a vector either
                std::vector<std::string> namesvector;
                namesvector.push_back(id2);
                network.insert( { id1, namesvector } );
            }


        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            if ( network.find(id) == network.end() ) {
                // person not as key in network
                std::cout << id << std::endl;
            } else {
                // person found as key in network
                std::cout << id << std::endl;
                print_command(network, id, 0);
            }

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            // So we need to calculate all the people under id in the network.
            // Guess we'll do it recursively using some sort of counter.

            if ( network.find(id) == network.end() ) {
                // name not in network = he has 0 recruits
                std::cout << 0 << std::endl;
            } else {
                // name is in network, which means they must have recruits
                int count = count_command(network, id);
                std::cout << count << std::endl;
            }

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            // So this needs to determine the max depth going to this id.
            // It actually seems that the assignment describes function wrong here,
            // so I'm not sure how to describe how it'll be done here.
            // Seems to me it will demand false logic.

            // Either way, this is kind of tricky. The command must also accept
            // an id that is not a key, but an element of a vector.
            // So first it will need to find where the id is, and then count
            // length of that chain.

            // If the id is not a key of network, that means chain depth is 1
            // in the logic of the functional example.
            // Else, we need to find the key, then recursively count how deep the chain
            // goes.

            if ( network.find(id) == network.end() ) {
                // id is not key, chain depth 1
                std::cout << 1 << std::endl;
            } else {
                // id is key. We begin recursion in the following function, if applicable.
                int depth = depth_command(network, id, 2);
                std::cout << depth << std::endl;
            }


        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
