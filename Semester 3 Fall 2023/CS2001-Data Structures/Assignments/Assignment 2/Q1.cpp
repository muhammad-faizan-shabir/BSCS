#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<class T> // template class
class Stack 
{
private:
    class node // node to  store data and next pointer
    {
    public:
        T data;
        node* next;
        node() // constructor
        {
            next = nullptr;
        }
    };
    node* topOfStackPtr; // top of stack pointer 
public:
    Stack() // constructor
    {
        topOfStackPtr = nullptr;
    };
   
    bool IsEmpty() // function to tell whether the stack is empty or not
    {
        if(topOfStackPtr==nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
     
    bool push(const T& val) // function to put data on top of stack
    {
        node* temp = new node;
        temp->data = val;
        temp->next = topOfStackPtr;
        topOfStackPtr = temp;
        return true;
    }

    bool pop(T& val) // function to remove data from top of stack and put it in a reference passed as parameter 
    {
        if(!IsEmpty())
        {
            val = topOfStackPtr->data;
            node* temp = topOfStackPtr;
            topOfStackPtr = topOfStackPtr->next;
            delete temp;
            return true;
        }
        else
        {
            return false;
        }
    }
     
    bool top(T& val) // function to look/peek at what's on top of stack
    {
        if(!IsEmpty())
        {
            val = topOfStackPtr->data;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    ~Stack() // destructor
    {
        T data;
        while(!IsEmpty())
        {
            pop(data);
        }
    }
};

class XMLData // class to store some imformation about xml tags
{
public:
    string tag; // this data member will store a tag name
    int lineNo; // this data member will store the line number on which the tag occured 

    XMLData(const string& t="", int ln=0) // constructor
    {
        tag = t;
        lineNo = ln;
    } 
};

int main()
{
    ifstream InputFile; // make an object to read the file contents
    InputFile.open("text.txt"); // open the file, in this case, the name of the file is text.txt
    if (!InputFile) // check whether the file opened successfully or not
    {
        std::cout << "Error! Cannot open file" << endl;
        system("pause");
        return 0;
    }

    Stack<XMLData> s1; // make a stack that can store XMLData objects
    string line; // this string variable will hold a line that comes from the file
    int lineNo = 0; // this variable will maintain the line number that is currently bieng parsed
    bool valid = true; // this flag will tell us at the end of the program whether there were errors in the file or not
    
    while (!InputFile.eof()) // keep on parsing the file until the file ends
    {
        int index = 0; // initialize index with zero every time we move to next line of the file
        lineNo++; // increment line number each time a line is read from the file
        getline(InputFile,line); // fetch a complete line from the file to parse
        
        if ((lineNo == 1) && (line[0] != '<' || line[1] != '?')) // in case we are at line 1 of the file and the header is missing then thats an error
        {
            std::cout << "Error! The header is missing from the start of file" << endl; // output the error
            valid = false; // file is no longer valid
        } 
        while (line[index]!='\0') // parse till the nd of the line
        {
            if (line[index] == '<') // we are interested only when a tag starts because thats when we can further explore other things like attributes and thier quotes
            {
                int startIndex = index; // keep a track of the starting index of the tag that is discovered
                index++; 
                while ((line[index]!='\0') && (line[index] != '>')&&(line[index]!='<')) // try to find the tag closes or not
                {
                    index++;
                }

                if ((line[index]=='\0')||(line[index]=='<')) // in the loop above if we do not find a closing angle bracket , this means that the tag is incomplete
                {
                    std::cout << "Error! Incomplete tag on line " << lineNo << endl; // output the error
                    valid = false; // file is no longer valid 
                    continue; // move to start of loop to investigate upcoming characters 
                }
                
                string tag = line.substr(startIndex, index - startIndex+1); // if the above IF block do not run then it means that the tag is complete so we extract that tag from the line 
                
                if ((lineNo!=1)&&(tag[0]=='<')&&(tag[1]=='?')) // in case we are not on line 1 and we encounter a header tag then thats an error since header can only come at the start
                {
                    std::cout << "Error! XML prolog on line "<<lineNo<< " must be at the beginning of the document." << endl; // output the error
                    valid = false; // file is no longer valid
                }
                else if ((tag[0]=='<')&&(tag[1]=='/')) // in case the tag starts with </ then thats a closing tag
                {
                    tag = tag.substr(2, tag.length() - 3); // refine the tag by removing '</' from its start and '>' from its end 
                    XMLData data; // make an object of XMLData
                    s1.top(data); // get data from top of stack 

                    if ((s1.IsEmpty()) || (data.tag != tag)) // in case the stack is empty or the opening tag from top of stack do not match with this closing tag then that's an error 
                    {
                        std::cout << "Error! Mismatched closing tag </" << tag << "> on line " << lineNo << " with opening tag <"<<data.tag<<"> on line "<<data.lineNo<< endl; // output the error
                        valid = false; // file is no longer valid
                        if(!s1.IsEmpty()) // in case the stack is not empty, pop the data from top of stack
                        {
                            s1.pop(data);
                        }
                        continue; // move to start of the loop to investigate upcoming characters
                    }
                    s1.pop(data); // in case there is a match, pop data from top of stack
                }
                else if ((tag[0] == '<') && (tag[1] == '!') && (tag[2] == '-') && (tag[3] == '-')) // if first four characeters of the tag are <!-- then thats a comment
                {
                    if ((tag[tag.length() - 3] != '-') || (tag[tag.length() - 2] != '-') || (tag[tag.length() - 1] != '>')) // if the comment is not closed properly then thats an error
                    {
                        std::cout << "Error! Unclosed comment on line " << lineNo << endl; // output the error
                        valid = false; // file is no longer valid
                    }
                }
                else // the only other interpretation is that its a starting/opening tag 
                {
                    if ((lineNo == 1) && (tag[0] == '<') && (tag[1] == '?'))
                    {
                        if ((tag[tag.length() - 2] != '?') || (tag[tag.length() - 1] != '>')) // if there is a header at the start but it is not closed properly then thats an error
                        {
                            std::cout << "Error! Unclosed header tag" << endl; // output the error
                            valid = false; // file is no longer valid
                        }
                    }

                    if(tag.find('=') != string::npos) // check if the opening tag contains any attributes by checking for '=' sign in the tag
                    {
                        int attributeNum = 1; // maintain the number of the attribute whose opening and closing quotes are bieng investigated 
                        char expect='\0'; // this character variable holds the expected closing quote
                        int i = 0; // this is an index to traverse the tag
                        while(tag[i]!='\0'&&tag[i]!=' ') // move till the first space after the name of the tag, this first space separates the tag and the first attribute 
                        {
                            i++;
                        }
                        i++;
                        while(tag[i]!='\0') // move till the end of the tag after first space
                        {
                            if((tag[i]=='=')&&(tag[i+1]!='\"') && (tag[i + 1] != '\'')) // case when an opening quote is missing
                            {
                                std::cout << "Error! missing opening quote  on line " << lineNo << " for attribute " << attributeNum << endl; // output the error
                                valid = false; // file is no longer valid
                                expect = '\0';
                            }
                            if((tag[i]=='=')&&((tag[i+1]=='\'')||(tag[i+1]=='\"'))) // set expected closing quote in case an opening quote exists
                            {
                                if(tag[i + 1] == '\"')
                                {
                                    expect = '\"';
                                }
                                else
                                {
                                    expect = '\'';
                                }
                            }
                            if(((tag[i]==' ')||(tag[i] == '>') || (tag[i] == '?')) && (tag[i - 1] != expect)) // if the closing quote is not present or is present but do not match with the expected closing quote then thats an error
                            {
                                std::cout << "Error! Missing or mismathced closing quote on line " << lineNo << " for attribute " << attributeNum << endl; // output the error
                                valid = false; // file is no longer valid
                            }
                            if(tag[i]==' ') // a space means that the current attribute is finished and next will start
                            {
                                attributeNum++;
                            }
                            if(tag[i]=='?'||tag[i]=='>') // '?' or '>' mean that the tag has ended so we stop traversing 
                            {
                                i = tag.length();
                            }
                            else
                            {
                                i++; // move to next character
                            }
                        }
                        tag = tag.substr(1, tag.find(" ") - 1); // extract tag name after dealing with attributes
                    }
                    else // case when there are no attributes
                    {
                        tag = tag.substr(1, tag.length() - 2); // extract tag name by removing '<' from the start and '>' from the end
                    }
                    if(tag.find("xml")== string::npos) // when pushing an opening tag on the stack, make sure that you don't push the xml header tag since it has no closing tag
                    {
                        s1.push(XMLData(tag, lineNo)); // push the object of XMLData with its tag name and line no where the tag opened
                    } 
                }
            }
            else
            {
                index++;
            }
        }
    }

    if((valid ==true)&&(s1.IsEmpty())) // check if the valid flag is still true or not
    {
        std::cout << "The XML file is valid" << endl; // the file has valid format if the flag is true
    }
    else // if file is not valid then empty the stack to identify those tags that opened but did not close
    {
        while (!s1.IsEmpty())
        {
            XMLData data;
            s1.pop(data);
            std::cout << "Error! Unclosed opening tag <" << data.tag << "> on line " << data.lineNo << endl;
        }
    }
    
    InputFile.close(); // close the file
    std::cout << endl; 
    system("pause");
    return 0;
}
