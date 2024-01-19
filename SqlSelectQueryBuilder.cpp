#include"SqlSelectQueryBuilder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder()
{
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) noexcept
{
	columns.push_back(column);
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) noexcept
{
	this->table = table;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) noexcept
{
	wheres[column] = value;
	return *this;
}

std::string SqlSelectQueryBuilder::get_select() noexcept
{
	return sql_select;
}

bool SqlSelectQueryBuilder::BuildQuery()
{
	if (table.empty()) { throw SQLException("SQL table missed!"); }
	if (!columns.empty())
	{
		sql_select = "SELECT ";
		for (const auto& it : columns)
		{
			(it == *columns.crbegin()) ? sql_select += it + " " : sql_select += it + ",";
		}
	}
	else
	{
		sql_select = "SELECT * ";
	}

	sql_select += "FROM " + table;

	if (!wheres.empty())
	{
		sql_select += " WHERE ";
		for (const auto& [col, value] : wheres)
		{
			(col == wheres.crbegin()->first) ? sql_select += col + "=" + value : sql_select += col + "=" + value + " AND ";
		}
	}
	sql_select += ";";
	return true;
}

SqlSelectQueryBuilder::~SqlSelectQueryBuilder()
{
}