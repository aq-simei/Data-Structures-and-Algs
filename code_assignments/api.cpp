#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void registerUser(string username, string password, unordered_map<string, string> &users, vector<string> &result)
{
  if (users.find(username) == users.end())
  {
    users[username] = password;
    result.push_back("Registered Successfully");
    
  }
  else
  {
    result.push_back("Username already exists");
    
  }
}

void userLogin(string username, string password, unordered_map<string, string> &users, vector<string> &result, Node & LoginData)
{
  if (users.find(username) == users.end())
  {
    
    result.push_back("Login Unsuccessful");
  }
  else
  {
    if (users.at(username) == password)
    { // password is correct
      if (LoginData.loggedIn == false)
      {                              // no one logged in yet
        LoginData.loggedIn = true ; // login
        LoginData.userName = username;
        result.push_back("Logged In Successfully");
      }
      else
      {                                         // someone already logged in
        result.push_back("Login Unsuccessful"); // fail
        
      }
    }
    else
    { // wrong password
      
      result.push_back("Login Unsuccessful");
    }
  }
}

void userLogout(string username, Node & LoginData, vector<string> &result)
{
  if (LoginData.userName == username)
  {
    LoginData.userName = ""; // clear login name
    LoginData.loggedIn = false; // clear login state
    result.push_back("Logout Successful");
  }
  else
  {
    result.push_back("Logout Unsuccessful");
  }
};

vector<string> tokens(string s, string del)
{
  int start = 0;
  int end = s.find(del);
  vector<string> response;

  while (end != -1)
  {
    string word = s.substr(start, end - start);

    start = end + del.size();
    end = s.find(del, start);

    response.push_back(word);
  };
  string word = s.substr(start, end - start);

  start = end + del.size();
  end = s.find(del, start);

  response.push_back(word);

  return response;
}

void printResult(vector<string> & result){
  for(int i = 0; i <= result.size() - 1; i++){
    cout << result[i] << endl;
  }
}
struct Node {
  bool loggedIn;
  string userName;
};

void api(vector<string> logs)
{
  Node LoginData;
  vector<string> result;
  unordered_map<string, string> users;
  queue<string> loginControl;
  for (int i = 0; i < logs.size(); i++)
  {
    vector<string> request = tokens(logs[i], " ");
    if (request[0] == "register")
    {
      registerUser(request[1], request[2], users, result);
    }
    else if (request[0] == "login")
    {
      userLogin(request[1], request[2], users, result, LoginData);
    }
    else if (request[0] == "logout")
    {
      userLogout(request[1], LoginData, result);
    }
  };
  printResult(result);
};

int main()
{
  vector<string> input = {"5",
"register david david123"
"register adam 1Adam1",
"login david david123",
"login adam 1adam1",
"logout david"};
  api(input);
  return 0;
}
