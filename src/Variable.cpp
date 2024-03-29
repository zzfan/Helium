#include "variable/Variable.hpp"
#include "util/DomUtil.hpp"
#include "type/TypeFactory.hpp"
#include <iostream>

Variable::Variable(std::shared_ptr<Type> type, const std::string& name)
: m_type(type), m_name(name) {
  // std::cout << "[Variable::Variable] "
  // << "create variable: " << name << " of type: " << type->GetName()
  // << std::endl;
}

std::string Variable::GetInputCode() const {
  return m_type->GetInputCode(m_name);
}
std::string Variable::GetOutputCode() const {
  return m_type->GetOutputCode(m_name);
}
std::string
Variable::GetInputSpecification() const {
  return m_type->GetInputSpecification();
}
std::string
Variable::GetOutputSpecification() const {
  return m_name + ":" + m_type->GetOutputSpecification();
}
