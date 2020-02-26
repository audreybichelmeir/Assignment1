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
  bool fileIsGood(string file);
  string toUpperFunction(string dnaString);
  float Probability(float aCounter, float tCounter, float gCounter, float cCounter, float sum, float aaCounter, float atCounter, float agCounter, float acCounter, float caCounter, float ccCounter, float ctCounter, float cgCounter, float taCounter, float tcCounter, float ttCounter, float tgCounter, float gaCounter, float gcCounter, float gtCounter, float ggCounter);
private:
};

  bool dna::fileIsGood(string file)
  {
    dna d2;
    string line = " ";
    double dnaLength = 0;
    double sum = 0;
    double mean = 0;
    //var
    double var = 0;
    double var2 = 0;
    double varFinal = 0;
    //std
    double std = 0;
    int lineCounter = 0;
    // dnaString
    string dnaString = " ";
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
        // sum
        var = str.length();
        dnaLength += str.length();
        cout << "SUM: " << dnaLength << endl;
        //mean
        mean = dnaLength / lineCounter;
        cout << "MEAN: " << mean << endl;
      }
      d2.toUpperFunction(dnaString);
      return true;
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
        cout << "VAR: " << varFinal << endl;
      }
      std = sqrt(varFinal);
      cout << "STD: " << std << endl;
    }
    else
    {
      cout << "Unable to open file" << endl;
      return false; // 0 - is not good & ask again where it's prompt would you like you to enter another file
    }
  }

  string dna::toUpperFunction(string dnaString)
  {
    cout << dnaString << endl;//single
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
    d3.Probability(aCounter, tCounter, gCounter, cCounter, sum, aaCounter, atCounter, agCounter, acCounter, caCounter, ccCounter, ctCounter, cgCounter, taCounter, tcCounter, ttCounter, tgCounter, gaCounter, gcCounter, gtCounter, ggCounter);
  }

  float dna::Probability(float aCounter, float tCounter, float gCounter, float cCounter, float sum, float aaCounter, float atCounter, float agCounter, float acCounter, float caCounter, float ccCounter, float ctCounter, float cgCounter, float taCounter, float tcCounter, float ttCounter, float tgCounter, float gaCounter, float gcCounter, float gtCounter, float ggCounter)
  {
    float aProbability = ((float) aCounter / (float) sum);
    cout << "A: " << aProbability << endl;
    float tProbability = ((float) tCounter / (float) sum);
    cout << "T: " << tProbability << endl;
    float gProbability = ((float) gCounter / (float) sum);
    cout << "G: " << gProbability << endl;
    float cProbability = ((float) cCounter / (float) sum);
    cout << "C: " << cProbability << endl;
    //bigram
    //A
    float aaProbability = ((float) aaCounter / (float) sum);
    cout << "AA: " << aaProbability << endl;
    float atProbability = ((float) atCounter / (float) sum);
    cout << "AT: " << atProbability << endl;
    float agProbability = ((float) agCounter / (float) sum);
    cout << "AG: " << agProbability << endl;
    float acProbability = ((float) acCounter / (float) sum);
    cout << "AC: " << acProbability << endl;
    //T
    float taProbability = ((float) taCounter / (float) sum);
    cout << "TA: " << taProbability << endl;
    float ttProbability = ((float) ttCounter / (float) sum);
    cout << "TT: " << ttProbability << endl;
    float tgProbability = ((float) tgCounter / (float) sum);
    cout << "TG: " << tgProbability << endl;
    float tcProbability = ((float) tcCounter / (float) sum);
    cout << "TC: " << tcProbability << endl;
    //C
    float caProbability = ((float) caCounter / (float) sum);
    cout << "CA: " << caProbability << endl;
    float ctProbability = ((float) ctCounter / (float) sum);
    cout << "CT: " << ctProbability << endl;
    float cgProbability = ((float) cgCounter / (float) sum);
    cout << "CG: " << cgProbability << endl;
    float ccProbability = ((float) ccCounter / (float) sum);
    cout << "CC: " << ccProbability << endl;
    //G
    float gaProbability = ((float) gaCounter / (float) sum);
    cout << "GA: " << gaProbability << endl;
    float gtProbability = ((float) gtCounter / (float) sum);
    cout << "GT: " << gtProbability << endl;
    float ggProbability = ((float) ggCounter / (float) sum);
    cout << "GG: " << ggProbability << endl;
    float gcProbability = ((float) gcCounter / (float) sum);
    cout << "GC: " << gcProbability << endl;

  }

  int main (int argc, char ** argv)
  {
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
        cout << "you are trash" << endl;
        continue;
      }
      else { //contains txt
        cout << "ok then" << endl;
      isGood = true;
      cout << d.fileIsGood(file) << endl;
      }
    }
    return 0;
  }
