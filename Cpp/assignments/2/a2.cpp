////////////////////////////////////////////////////////////////////////////////
// File Name:      a2.cpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    The source file for a2.
//
// IMPORTANT NOTE: THIS IS THE ONLY FILE THAT YOU SHOULD MODIFY FOR A2.
//                 You SHOULD NOT MODIFY any of the following:
//                   1. Name of the functions/methods.
//                   2. The number and type of parameters of the functions.
//                   3. Return type of the functions.
////////////////////////////////////////////////////////////////////////////////

#include "a2.hpp"
#include "trim.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

void cleanData(ifstream &inFile, ofstream &outFile,
               unordered_set<string> &stopwords) {
    // TODO: Implement this method.
    // # of lines of code in Gerald's implementation: 13
    // Do the following operations on each review before
    // storing it to the output file:
    //   1. Replace hyphens with spaces.
    //   2. Split the line of text into individual words.
    //   3. Remove the punctuation marks from the words.
    //   4. Remove the trailing and the leading whitespaces in each word.
    //   5. Remove the empty words.
    //   6. Remove words with just one character in them. You should NOT remove
    //      numbers in this step because if you do so, you'll lose the ratings.
    //   7. Remove stopwords.
    string reviewLine;
    while(getline(inFile, reviewLine)) {
        // replace all hyphens to spaces
        replaceHyphensWithSpaces(reviewLine);
        // create a vector of string for storing seperated words
        vector<string> inTokens;
        // split the line into tokens and put them in the vector
        splitLine(reviewLine, inTokens);

        vector<string> outTokens;

        removeWhiteSpaces(inTokens);
        removePunctuation(inTokens, outTokens);
        removeSingleLetterWords(outTokens);
        removeEmptyWords(outTokens);
        removeStopWords(outTokens, stopwords);

        // write words into the output file
        stringstream outLiness;
        for (auto it = outTokens.begin(); it != outTokens.end(); ++it) {
            outLiness << *it << " ";
        }
        string outLine = outLiness.str();
        outFile << rtrim(outLine) << endl;
    }
}

void fillDictionary(std::ifstream &newInFile,
                    std::unordered_map<std::string, std::pair<long, long> > &dict) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 20
    string newReviewLine;
    while(getline(newInFile, newReviewLine)) {
        // set initial count equal to 1
        // grab the rating of each review and convert it into type long
        long rating = newReviewLine[0] - '0';
        long count(1);

        // create a vector of string for storing seperated words
        // It represents tokens along one line
        vector<string> inTokens;
        splitLine(newReviewLine, inTokens);
        // remove empty words in each line;
        removeEmptyWords(inTokens);

        // iterate through all words and record their counts and ratings
        for (auto it = next(inTokens.begin()); it != inTokens.end(); ++it) {
            // for this particular word, check if it is already in the keys
            // collection. If it does, continue operating on the values.
            // Otherwise, add it into the map.
            unordered_map<string, pair<long, long> >::const_iterator got
                = dict.find(*it);

            if (got == dict.end()) {
                dict[*it].first = rating;
                dict[*it].second = count;
            }
            else {
                pair<long, long> currPair = got -> second;
                dict[*it].first = currPair.first + rating;
                dict[*it].second = ++currPair.second;
            }
        }
    }
}

void fillStopWords(std::ifstream &inFile,
                   std::unordered_set<std::string> &stopwords) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    string stopword;
    while(getline(inFile, stopword)) {
        stopwords.insert(stopword);
    }
}

void rateReviews(std::ifstream &testFile,
                 std::unordered_map<std::string, std::pair<long, long>> &dict,
                 std::ofstream &ratingsFile) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 20
    string testReviewLine;
    while(getline(testFile, testReviewLine)) {
        // if the review line is empty, write a neutral rating to this review
        if (testReviewLine == "") {
            double neutral = 2.00;
            ratingsFile << neutral  << endl;
        } else {
            // otherwise start to search words
            double initRating = 0.00;
            vector<string> inTokens;
            // split the line into tokens and put them in the vector
            splitLine(testReviewLine, inTokens);
            // remove the emptyword
            removeEmptyWords(inTokens);

            // loop through each token vector to give the correct ratings
            for (auto it = inTokens.begin(); it != inTokens.end(); ++it) {
                // search the token through the map
                // if found, pair it with its average rating
                // if not, give it a netural rating
                unordered_map<string, pair<long, long> >::const_iterator got
                    = dict.find(*it);

                    if (got == dict.end()) {
                        initRating = initRating + 2.00;
                    }
                    else {
                        pair<long, long> currPair = got -> second;
                        double currRating = double(currPair.first) / double(currPair.second);
                        initRating = initRating + currRating;
                    }
                }
                double reviewRating = initRating / inTokens.size();
                ratingsFile << std::setprecision(2) << std::fixed << reviewRating << endl;
        }
    }
}

void removeEmptyWords(std::vector<std::string> &tokens) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    tokens.erase(remove(tokens.begin(), tokens.end(), ""), tokens.end());
}

void removePunctuation(std::vector<std::string> &inTokens,
                       std::vector<std::string> &outTokens) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 10
    for (auto it = inTokens.begin(); it != inTokens.end(); ++it) {
        (*it).erase(std::remove_if((*it).begin(), (*it).end(), ::ispunct),
                    (*it).end());
        outTokens.push_back(*it);
    }
}

void removeSingleLetterWords(std::vector<std::string> &tokens) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    std::vector<std::string> copy_tokens = tokens;
    for (auto it = copy_tokens.begin(); it != copy_tokens.end(); ++it) {
        if ((*it).size() == 1 && ! isdigit((*it)[0])) {
            tokens.erase(std::remove(tokens.begin(), tokens.end(), *it), tokens.end());
        }
    }
}

void removeStopWords(std::vector<std::string> &tokens,
                     std::unordered_set<std::string> &stopwords) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    /*
    for (auto it = stopwords.begin(); it != stopwords.end(); ++it) {
        auto got = std::find(tokens.begin(), tokens.end(), *it);
        if (got != tokens.end()) { // is a stopword
            tokens.erase(std::remove(tokens.begin(), tokens.end(), *it), tokens.end());
        }
    }*/
    std::vector<std::string> copy_tokens = tokens;
    for (auto it = copy_tokens.begin(); it != copy_tokens.end(); ++it) {
        std::unordered_set<std::string>::iterator got = stopwords.find(*it);
        if (got != stopwords.end()) {
            tokens.erase(std::remove(tokens.begin(), tokens.end(), *it), tokens.end());
        }

    }
}

void removeWhiteSpaces(std::vector<std::string> &tokens) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    // You may want to use the trim() method from the trim.*pp files in a2.
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        *it = trim(*it);
    }
}

void replaceHyphensWithSpaces(std::string &line) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 5
    std::replace(line.begin(), line.end(), '-', ' ');
}

void splitLine(std::string &line, std::vector<std::string> &words) {
    // TODO: Implement this method.
    // approximate # of lines of code in Gerald's implementation: < 10
    istringstream iss(line);
    while(iss) {
        string word;
        iss >> word;
        words.push_back(word);
    }
}
