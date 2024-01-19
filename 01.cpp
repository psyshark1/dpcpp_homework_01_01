#include"SqlSelectQueryBuilder.h"

int main()
{
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	try
	{
		query_builder.BuildQuery();
		//static_assert(query_builder.BuildQuery(),
			//"SELECT name,phone FROM students WHERE id=42 AND name=John;");

		std::cout << query_builder.get_select() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
