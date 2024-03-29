#ifndef __UNION_SNIPPET_HPP__
#define __UNION_SNIPPET_HPP__

#include "snippet/Snippet.hpp"
#include "resolver/Ctags.hpp"

class UnionSnippet : public Snippet {
public:
  UnionSnippet(const std::string& code, const std::string& filename, int line_number);
  UnionSnippet(const CtagsEntry& ce);
  virtual ~UnionSnippet() {}
  virtual std::string GetName() {return m_name;}
  virtual char GetType() {return m_type;}
  virtual std::string GetCode() {return m_code;}
  virtual std::set<std::string> GetKeywords() {return m_keywords;}
  virtual std::string GetFilename() const {return m_filename;}
  virtual int GetLineNumber() const {return m_line_number;}
private:
  std::string m_code;
  std::string m_name;
  std::string m_alias;
  char m_type;
  std::string m_filename;
  int m_line_number;
  std::set<std::string> m_keywords;
};

#endif
