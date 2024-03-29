#include "segment/Segment.hpp"
#include "util/DomUtil.hpp"

#include <iostream>

Segment::Segment () {}
Segment::~Segment () {}

void Segment::PushBack(pugi::xml_node node) {
  m_nodes.push_back(node);
}
void Segment::PushFront(pugi::xml_node node) {
  m_nodes.insert(m_nodes.begin(), node);
}
void Segment::Clear() {
  m_nodes.clear();
}

std::vector<pugi::xml_node> Segment::GetNodes() const {
  return m_nodes;
}

pugi::xml_node
Segment::GetFirstNode() const {
  if (m_nodes.empty()) {
    // this should be a node_null
    return pugi::xml_node();
  } else {
    return m_nodes[0];
  }
}

void Segment::Print() {
  std::cout<<"=======Segment======="<<std::endl;
  for (auto it=m_nodes.begin();it!=m_nodes.end();it++) {
    // it->print(std::cout);
    std::cout<<DomUtil::GetTextContent(*it)<<std::endl;
  }
}

std::string
Segment::GetText() {
  std::string s;
  for (auto it=m_nodes.begin();it!=m_nodes.end();it++) {
    s += DomUtil::GetTextContent(*it) + '\n';
  }
  return s;
}
