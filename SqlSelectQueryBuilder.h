#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"SQLException.h"

class SqlSelectQueryBuilder
{
public:
	SqlSelectQueryBuilder();
	SqlSelectQueryBuilder& AddColumn(const std::string& column) noexcept;
	SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) noexcept;
	SqlSelectQueryBuilder& AddFrom(const std::string& table) noexcept;
	bool BuildQuery();
	std::string get_select() noexcept;
	~SqlSelectQueryBuilder();

private:
	std::string sql_select;
	std::string table;
	std::vector<std::string> columns;
	std::map<std::string, std::string> wheres;
};