#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

//^^ std
  std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
  {
      str.erase(0, str.find_first_not_of(chars));
      return str;
  }

  std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
  {
      str.erase(str.find_last_not_of(chars) + 1);
      return str;
  }

  std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
  {
      return ltrim(rtrim(str, chars), chars);
  }

class dna
{
public:
  string filePrompt(string user);
  bool fileIsGood(string file);
  string toUpperFunction(float mean, float std, string dnaString);
  float Probability(float mean2, float std2, float biSum, float aCounter, float tCounter, float gCounter, float cCounter, float sum, float aaCounter, float atCounter, float agCounter, float acCounter, float caCounter, float ccCounter, float ctCounter, float cgCounter, float taCounter, float tcCounter, float ttCounter, float tgCounter, float gaCounter, float gcCounter, float gtCounter, float ggCounter);
  int Gaussian();
private:
};

  bool dna::fileIsGood(string file)
  {
    dna d2;
    string line = "";
    float dnaLength = 0;
    float sum = 0;
    float mean = 0;
    //var
    float var = 0;
    float var2 = 0;
    float varFinal = 0;
    //std
    float std = 0;
    int lineCounter = 0;
    // dnaString
    string dnaString = "";
    ifstream myfile (file);
    if (myfile.is_open())
    {
      while ( myfile.good() )
      {
        getline(myfile,line);
        std::string str = line;
        trim(str);
        lineCounter++;
        dnaString.append(line);
        dnaString.append("\n");
        // sum
        var = str.length();
        dnaLength += str.length();
      }

      //cout << "SUM: " << dnaLength << endl;
      //mean
      mean = dnaLength / lineCounter;
      //cout << "MEAN: " << mean << endl;

      myfile.close();
      myfile.open(file);
      if (myfile.is_open())
      {
        while ( myfile.good() )
        {
          getline(myfile,line);
          std::string str = line;
          trim(str);
          var = str.length();
          var2 += (var - mean) * (var - mean);
        }
        varFinal = var2 / lineCounter;
        //cout << "VAR: " << varFinal << endl;
      }
      std = sqrt(varFinal);
      //cout << "STD: " << std << endl;

      ofstream dnaout;
      dnaout.open("audreybichelmeir.txt");
      dnaout << "Name: Audrey Bichelmeir" << "\n";
      dnaout << "ID Number: 2327865" << "\n";
      dnaout << "Section: CPSC 350-02" << "\n";
      dnaout << "The Sum of the length of the DNA strings is: " << dnaLength << "\n";
      dnaout << "The Mean of the length of the DNA strings is: " << mean << "\n";
      dnaout << "The variance of the length of the DNA strings is: " << varFinal << "\n";
      dnaout << "The Standard Deviation of the length of the DNA stings is " << std << "\n";

      dnaout.close();//close reading file

      d2.toUpperFunction(mean, std, dnaString);
    }
    else
    {
      cout << "Unable to open file" << endl;
      // return false; // 0 - is not good & ask again where it's prompt would you like you to enter another file
    }
  }

  string dna::toUpperFunction(float mean, float std, string dnaString)
  {
    float mean2 = mean;
    float std2 = std;
    //cout << dnaString << endl;//single
    int aCounter = 0;
    int tCounter = 0;
    int gCounter = 0;
    int cCounter = 0;
    //bigram
    //A
    int aaCounter = 0;
    int acCounter = 0;
    int atCounter = 0;
    int agCounter = 0;
    //C
    int caCounter = 0;
    int ccCounter = 0;
    int ctCounter = 0;
    int cgCounter = 0;
    //T
    int taCounter = 0;
    int tcCounter = 0;
    int ttCounter = 0;
    int tgCounter = 0;
    //G
    int gaCounter = 0;
    int gcCounter = 0;
    int gtCounter = 0;
    int ggCounter = 0;

    float sum = 0;
    dna d3;
    char dnaString2 = '\0';
    for (int i = 0; i < dnaString.length(); i+=2)
    {
      dnaString2 = toupper(dnaString[i]);
      char dnaString3 = toupper(dnaString[i+1]);
      if (dnaString2 == 'A')
      {
        aCounter++;
          //bigram
          if (dnaString3 == 'A')
            {
              aaCounter++;
            }
          else if (dnaString3 == 'T')
            {
              atCounter++;
            }
          else if (dnaString3 == 'G')
            {
              agCounter++;
            }
          else if (dnaString3 == 'C')
            {
              acCounter++;
            }
      }
      else if (dnaString2 == 'T')
      {
        tCounter ++;
        if (dnaString3 == 'A')
          {
            taCounter++;
          }
        else if (dnaString3 == 'T')
          {
            ttCounter++;
          }
        else if (dnaString3 == 'G')
          {
            tgCounter++;
          }
        else if (dnaString3 == 'C')
          {
            tcCounter++;
          }
      }

      if (dnaString2 == 'G')
      {
        gCounter ++;
          if (dnaString3 == 'A')
            {
              gaCounter++;
            }
        else  if (dnaString3 == 'T')
            {
              gtCounter++;
            }
        else if (dnaString3 == 'G')
            {
              ggCounter++;
            }
        else if (dnaString3 == 'C')
            {
              gcCounter++;
            }
      }

      if (dnaString2 == 'C')
      {
        cCounter ++;
          if (dnaString3 == 'A')
          {
              caCounter++;
          }
          else if (dnaString3 == 'T')
          {
              ctCounter++;
          }
          else if (dnaString3 == 'G')
          {
              cgCounter++;
          }
          else if (dnaString3 == 'C')
            {
              ccCounter++;
            }
      }
    }
    sum = aCounter + tCounter + gCounter + cCounter;
    float biSum = aaCounter + atCounter + agCounter + acCounter + caCounter + ccCounter + ctCounter + cgCounter + taCounter + tcCounter + ttCounter + tgCounter + gaCounter + gcCounter + gtCounter + ggCounter;
    d3.Probability(mean2, std2, biSum, aCounter, tCounter, gCounter, cCounter, sum, aaCounter, atCounter, agCounter, acCounter, caCounter, ccCounter, ctCounter, cgCounter, taCounter, tcCounter, ttCounter, tgCounter, gaCounter, gcCounter, gtCounter, ggCounter);
  }

  float dna::Probability(float mean2, float std2, float biSum, float aCounter, float tCounter, float gCounter, float cCounter, float sum, float aaCounter, float atCounter, float agCounter, float acCounter, float caCounter, float ccCounter, float ctCounter, float cgCounter, float taCounter, float tcCounter, float ttCounter, float tgCounter, float gaCounter, float gcCounter, float gtCounter, float ggCounter)
  {
      dna d4;
    float mean3 = mean2;
    float std3 = std2;
    cout << "MEAN 3: " << mean3 << endl;
    cout << "STD 3: " << std3 << endl;

    float aProbability = ((float) aCounter / biSum);
    cout << "A: " << aProbability << endl;
    float tProbability = ((float) tCounter / biSum);
    cout << "T: " << tProbability << endl;
    float gProbability = ((float) gCounter / biSum);
    cout << "G: " << gProbability << endl;
    float cProbability = ((float) cCounter / biSum);
    cout << "C: " << cProbability << endl;
    //bigram
    //A
    float aaProbability = ((float) aaCounter / biSum);
    cout << "AA: " << aaProbability << endl;
    float atProbability = ((float) atCounter / biSum);
    cout << "AT: " << atProbability << endl;
    float agProbability = ((float) agCounter / biSum);
    cout << "AG: " << agProbability << endl;
    float acProbability = ((float) acCounter / biSum);
    cout << "AC: " << acProbability << endl;
    //T
    float taProbability = ((float) taCounter / biSum);
    cout << "TA: " << taProbability << endl;
    float ttProbability = ((float) ttCounter / biSum);
    cout << "TT: " << ttProbability << endl;
    float tgProbability = ((float) tgCounter / biSum);
    cout << "TG: " << tgProbability << endl;
    float tcProbability = ((float) tcCounter / biSum);
    cout << "TC: " << tcProbability << endl;
    //C
    float caProbability = ((float) caCounter / biSum);
    cout << "CA: " << caProbability << endl;
    float ctProbability = ((float) ctCounter / biSum);
    cout << "CT: " << ctProbability << endl;
    float cgProbability = ((float) cgCounter / biSum);
    cout << "CG: " << cgProbability << endl;
    float ccProbability = ((float) ccCounter / biSum);
    cout << "CC: " << ccProbability << endl;
    //G
    float gaProbability = ((float) gaCounter / biSum);
    cout << "GA: " << gaProbability << endl;
    float gtProbability = ((float) gtCounter / biSum);
    cout << "GT: " << gtProbability << endl;
    float ggProbability = ((float) ggCounter / biSum);
    cout << "GG: " << ggProbability << endl;
    float gcProbability = ((float) gcCounter / biSum);
    cout << "GC: " << gcProbability << endl;

    ofstream dnaout;
    dnaout.open("audreybichelmeir.txt", std::ios_base::app);
    dnaout << "Here is the relative probability of each nucleotide:" << "\n";
    dnaout << "A: " << aProbability << "\n";
    dnaout << "T: " << tProbability << "\n";
    dnaout << "G: " << gProbability << "\n";
    dnaout << "C: " << cProbability << "\n";
    dnaout << "Here is the relative probability of each nucleotide bigram:" << "\n";
    dnaout << "AA: " << aaProbability << "\n";
    dnaout << "AT: " << atProbability << "\n";
    dnaout << "AG: " << agProbability << "\n";
    dnaout << "AC: " << acProbability << "\n";
    dnaout << "TA: " << taProbability << "\n";
    dnaout << "TT: " << ttProbability << "\n";
    dnaout << "TG: " << tgProbability << "\n";
    dnaout << "TC: " << tcProbability << "\n";
    dnaout << "GA: " << gaProbability << "\n";
    dnaout << "GT: " << gtProbability << "\n";
    dnaout << "GG: " << ggProbability << "\n";
    dnaout << "GC: " << gcProbability << "\n";
    dnaout << "CA: " << caProbability << "\n";
    dnaout << "CT: " << ctProbability << "\n";
    dnaout << "CG: " << cgProbability << "\n";
    dnaout << "CC: " << ccProbability << "\n";

    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    string dnaStringG = "";
    dnaout << "Generated 1000 DNAs: \n";

    for(int i = 0; i < 1000; ++i)
    {
      a = rand() / (double)RAND_MAX;
      b = rand() / (double)RAND_MAX;
      c = sqrt(-2.0 * log(a)) * cos(2.0 * M_PI * b);
      float d = std3 * c + mean3; // length of dna

      for (int j = 0; j < d; ++j)
      {
        float e = rand()/(double)RAND_MAX;
        if(e > 0 && e <= aProbability)
        {
          dnaout << "A";
        }
        if(e > aProbability && e <= aProbability+tProbability )
        {
          dnaout << "T";
        }
        if(e > aProbability+tProbability && e <= aProbability+tProbability+gProbability)
        {
          dnaout << "G";
        }
        if(e > aProbability+tProbability+gProbability && e <= 1)
        {
          dnaout << "C";
        }
      }

      dnaout << "\n";
    }
  dnaout.close();
  //finally asking for a file again
   cout << "would you like to enter another file? Type 'Y' for yes and 'N' for no" << endl;
  string userInput;
  while(true)
  {
    cin >> userInput;
    //toupper(userInput);

    if (userInput == "Y" || "y"){
      d4.filePrompt(userInput);
    }
    else if (userInput == "N" || "n"){
      break;
      exit(0);
      //exit(1);
      //exit(2);
    }
    else{
      cout << "That is not correct!" << endl;
      continue;
    }
  }

  }

string dna::filePrompt(string user)
{
  ///
  srand(time(NULL)); // resets rand #
  int txtFinder;
  dna d;
  string file;

  bool isGood = false; // borrowed intarray.cpp from Ryan Millares

  while(!isGood)
  {
    cout << "Enter file name: (example: DNA.txt)" << endl;
    cin >> file;
    txtFinder = file.find(".txt");
    if (txtFinder == string::npos) // does not contain txt
    {
      cout << "File Can not be found" << endl;
      continue;
    }
    else { //contains txt
    isGood = true;
    cout << d.fileIsGood(file) << endl;
    }
  }
  ///
}

  int main (int argc, char ** argv)
  {
    int txtFinder;
    dna d;
    string file;
    bool isGood = false;
    bool fileExist = false;
    string error =  "File Can not be found";

    srand(time(NULL)); // resets rand #
    if (argc > 1)
    {
        fileExist = true;
        file = argv[1];
        cout << "File Name: " << file << endl;

        while(!isGood)
        {
          // cout << "Enter file name: (example: DNA.txt)" << endl;
          // cin >> file;
          txtFinder = file.find(".txt");
          if (txtFinder == string::npos) // does not contain txt
          {
            cin >> error;
            d.filePrompt(error);
            break;
          }
          else { //contains txt
          isGood = true;
          cout << d.fileIsGood(file) << endl;
          }
        }
    }

    // bool isGood = false; // borrowed intarray.cpp from Ryan Millares
    //
    // while(!isGood)
    // {
    //   // cout << "Enter file name: (example: DNA.txt)" << endl;
    //   // cin >> file;
    //   txtFinder = file.find(".txt");
    //   if (txtFinder == string::npos) // does not contain txt
    //   {
    //     cout << "File Can not be found" << endl;
    //     continue;
    //   }
    //   else { //contains txt
    //   isGood = true;
    //   cout << d.fileIsGood(file) << endl;
    //   }
    // }
    return 0;
  }
