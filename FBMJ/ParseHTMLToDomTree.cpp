/*
 * ParseHTMLToDomTree.cpp
 *
Parse HTML string to DOM Tree
找到target string，并且打印出来path
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

struct DOMTreeNode
{
  string tag;
  string content;
  vector<DOMTreeNode*> children;
  DOMTreeNode(string t): tag(t){}
};

pair<string, string> parseHtml(string& html, int& i)
{
  int len = html.length();
  string text, tag;
  while(i < len && html[i] != '<')
  {
    text += html[i++];
  }
  i++; // skip '<'

  while(i < len && html[i] != '>')
  {
    tag += html[i++];
  }
  i++; // skip '>'

  cout << "text is "<<text<<"  tag is "<<tag<<endl;
  return {text, tag};
}


DOMTreeNode* parseHtmlToDom(string html)
{
  int len = html.length(), i = 0;

  auto item = parseHtml(html, i);
  if(item.second.empty()) return NULL;

  DOMTreeNode* root = new DOMTreeNode(item.second);
  stack<DOMTreeNode*> table;

  table.push(root);

  while(i < len)
  {
    item = parseHtml(html, i);
    if(item.second[0] != '/')  // open tag
    {
      table.top()->content = item.first;
      DOMTreeNode* node = new DOMTreeNode(item.second);
      table.top()->children.push_back(node);
      table.push(node);
    }
    else // closing tag
    {
      if(!item.first.empty())table.top()->content = item.first;
      table.pop();
    }
  }

  return root;
}


// if we need to find the target string and print path, then
bool findPathForString(DOMTreeNode* root, string word, string& path)
{
  if(root->content == word)
  {
    return true;
  }

  for(auto child : root->children)
  {
    int oriSize = path.length();
    path += "/" + child->tag;
    if(findPathForString(child, word, path)) return true;
    path.resize(oriSize);
  }

  return false;
}

void test(DOMTreeNode* root) {
    if (!root) {
        return;
    }
    cout << "(" << root->tag << ") (" << root->content << ")" << endl;

    for (DOMTreeNode* p: root->children) {
        test(p);
    }
}

int main(int argc, char ** argv)
{
  string html="<html><head><title>Test</title></head><body>It works!<p>Baobao niuniude!</p></body></html>";

  DOMTreeNode* root = parseHtmlToDom(html);

  test(root);

  string path;
  path = "/html";
  cout << findPathForString(root, "Baobao niuniude!", path)<< endl;
  cout << path << endl;

}

