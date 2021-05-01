#include<iostream>
#include<fstream>
using namespace std;

class Component {
    public:
    string open(string tagName) {
        return ("<" + tagName + ">");
    }

    string close(string tagName) {
        return ("</" + tagName + ">");
    }
};

class HtmlTag : public Component {
    public:
    string html() {
        string tagName = "html";
        string htmlElements = head() + body() + "\n";
        return OpenAndCloseTag(tagName, htmlElements);
    }

    private:
    string OpenAndCloseTag(string tagName, string mid) {
        return "\n"+open(tagName)+mid+close(tagName);
    }

    string head() {
        string tagName = "head";
        return OpenAndCloseTag(tagName, title()+"\n");
    }

    string title() {
        string tagName = "title";
        string text ="HTML generator";
        return OpenAndCloseTag(tagName, text);
    }
    string body() {
        string tagName = "body";
        string bodyElements = h1() + label() + textArea() + button() +"\n";
        return OpenAndCloseTag(tagName, bodyElements);
    }
    string h1() {
        string tagName = "h1";
        string text = "Input";
        return OpenAndCloseTag(tagName, text);
    }
    string label() {
        string tagName = "label";
        string text = "comment:";
        return OpenAndCloseTag(tagName, text) + "<br>";
    }
    string textArea() {
        string tagName = "textarea";
        return OpenAndCloseTag(tagName, "") + "<br>";
    }

    string button() {
        string tagName = "button";
        string text = "Submit";
        return "\n"+open(tagName+" type='Submit'")+text+close(tagName);
    }
};

int main() {
    HtmlTag htmlTag;
    ofstream htmlfile("index.html");
    htmlfile << htmlTag.html();
    htmlfile.close();
    cout<<"HTML file was successfully created.";
    return 0;
}