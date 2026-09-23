#pragma once
#include <iostream>
#include <vector>

namespace History {
    class linkNode {
    private:
        std::vector<linkNode*> reference;
        linkNode* dereference;
        std::vector<int> position;
    public:
        linkNode();

        linkNode(int x, int y){
            position = {x, y};
        };

        linkNode(int x, int y, linkNode* df){
            position = {x, y};
            dereference = df;
        }

        void setNode(int x, int y);

        void addReference(linkNode* rf);

        void addDereference(linkNode* df);

        linkNode* getDereference();

        std::vector<int> getPosition();

        int getRefenceSize();
    };

    class linkList {
        private:
            std::vector<linkNode> list;
        public:
            void createNode(int x, int y);
            void createNode(int x, int y, linkNode* df);
            int getSize();
    };


}



