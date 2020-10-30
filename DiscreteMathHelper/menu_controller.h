/*
	Nguyen Nguyen
	Discrete Math Helper
	October 24, 2020
*/

#pragma once
#include <iostream>
#include <vector>
#include "helper.h"

class MenuGroup
{
public:
    MenuGroup() { };
	MenuGroup(const std::string& title) : text(title) { };

	void addMenuItem(const std::string& title, void(*f)())
	{
		data.push_back(std::make_pair(title, f));
	}

	std::string getText() const
	{
		return text;
	}

	size_t size() const
	{
		return data.size();
	}

	std::vector<std::pair<std::string, void(*)()>>& getData()
	{
		return data;
	}

private:
	std::string text;
	std::vector<std::pair<std::string, void(*)()>> data;
};

class MenuController
{
public:
	MenuController() { };
	MenuController(const std::string& title) :text(title) { };

    void show();
    void addGroup(MenuGroup& group);
    void setMenuExitKey(const std::string& key);
    
private:
	std::string text;
    std::string menuExitKey;
	std::vector<MenuGroup> groups;
    
    void printMenu() const;
    void choose(const std::string& id);
    std::string getMenuSelection() const;
    bool isValidMenuID(const std::string& id) const;
};

void MenuController::show()
{
    std::string selectedMenu;
    do
    {
        printMenu();
        selectedMenu = getMenuSelection();
        choose(selectedMenu);
    } while (selectedMenu != menuExitKey);
}

void MenuController::addGroup(MenuGroup& group)
{
    groups.push_back(group);
}

void MenuController::setMenuExitKey(const std::string& key)
{
    menuExitKey = key;
}

void MenuController::printMenu() const
{
    std::cout << std::endl;
    if (!text.empty())
    {
        std::cout << text << std::endl << std::endl;
    }

    size_t groupLen = groups.size();
    for (int i = 0; i < groupLen; ++i)
    {
        auto group = groups.at(i);

        std::cout << "  " << group.getText() << std::endl;

        size_t menuLen = group.getData().size();
        for (int j = 0; j < menuLen; ++j)
        {
            std::cout << '\t' << (i + 1) << '.' << (j + 1) << ' '
                << group.getData().at(j).first << std::endl;
        }
    }
    
    if (!menuExitKey.empty())
    {
        std::cout << "\n(Enter " << menuExitKey << " to exit.)" << std::endl;
    }
}

void MenuController::choose(const std::string& id)
{
    long pos = id.find('.');
    if (pos > 0)
    {
        int groupID = std::stoi(id.substr(0, pos));
        int subMenuID = std::stoi(id.substr(pos + 1));

        if (groupID > 0 && subMenuID > 0)
        {
            std::cout << std::endl << "=========== "
                << groups.at(groupID - 1).getData().at(subMenuID - 1).first
                << " ===========" << std::endl;
            Helper::repeat(groups.at(groupID - 1).getData().at(subMenuID - 1).second);
        }
    }
}

std::string MenuController::getMenuSelection() const
{
    std::string input;

    std::cout << "Your selection: ";
    std::cin >> input;

    while (input != menuExitKey && !isValidMenuID(input))
    {
        std::cout << "\nInvalid selection.\nYour selection: ";
        std::cin >> input;
    }
    
    return input;
}

bool MenuController::isValidMenuID(const std::string& id) const
{
    long pos = id.find('.');
    
    if (pos > 0 && pos != id.length() - 1)
    {
        int groupID = std::stoi(id.substr(0, pos));
        int subMenuID = std::stoi(id.substr(pos + 1));
        return groupID <= groups.size() && subMenuID <= groups.at(groupID - 1).size();
    }
    else
    {
        return false;
    }
}
