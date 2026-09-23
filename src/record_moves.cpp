#include "../input/record_moves.h"

namespace History {
    void linkList::createNode(int x, int y){
        linkNode newNode(x, y);
        list.push_back(newNode);
    };

    void linkList::createNode(int x, int y, linkNode* df){
        linkNode newNode(x, y, df);
        df->addReference(&newNode);
        newNode.addDereference(df);
        list.push_back(newNode);
    };

    int linkList::getSize(){
        return list.size();
    }

    std::vector<int> linkNode::getPosition(){
        return position;
    }

    void linkNode::setNode(int x, int y){
        position = {x, y};
    }

    void linkNode::addReference(linkNode* rf){
        reference.push_back(rf);
    }

    void linkNode::addDereference(linkNode* df){
        dereference = df;
    }

    linkNode* linkNode::getDereference(){
        return dereference;
    }

    int linkNode::getRefenceSize(){
        return reference.size();
    }
}