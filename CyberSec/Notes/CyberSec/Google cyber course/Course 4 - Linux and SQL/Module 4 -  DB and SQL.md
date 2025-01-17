![[Pasted image 20250112132808.png]]
![[Pasted image 20250112132843.png]]
![[Pasted image 20250112133002.png]]
# SQL filtering versus Linux filtering

Previously, you explored the Linux commands that allow you to filter for specific information contained within files or directories. And, more recently, you examined how SQL helps you efficiently filter for the information you need. In this reading, you'll explore differences between the two tools as they relate to filtering. You'll also learn that one way to access SQL is through the Linux command line.

## **Accessing SQL**

There are many interfaces for accessing SQL and many different versions of SQL. One way to access SQL is through the Linux command line.

To access SQL from Linux, you need to type in a command for the version of SQL that you want to use. For example, if you want to access SQLite, you can enter the command **sqlite3** in the command line.

After this, any commands typed in the command line will be directed to SQL instead of Linux commands.

## **Differences between Linux and SQL filtering** 

Although both Linux and SQL allow you to filter through data, there are some differences that affect which one you should choose.

### **Purpose**

Linux filters data in the context of files and directories on a computer system. It’s used for tasks like searching  for specific files, manipulating file permissions, or managing processes. 

SQL is used to filter data within a database management system. It’s used for querying and manipulating data stored in tables and retrieving specific information based on defined criteria. 

### **Syntax**

Linux uses various commands and command-line options specific to each filtering tool. Syntax varies depending on the tool and purpose. Some examples of Linux commands are find, sed, cut, e grep

SQL uses the Structured Query Language (SQL), a standardized language with specific keywords and clauses for filtering data across different SQL databases. Some examples of SQL keywords and clauses are WHERE, SELECT, JOIN

### **Structure**

SQL offers a lot more structure than Linux, which is more free-form and not as tidy.

For example, if you wanted to access a log of employee log-in attempts, SQL would have each record separated into columns. Linux would print the data as a line of text without this organization. As a result, selecting a specific column to analyze would be easier and more efficient in SQL.

In terms of structure, SQL provides results that are more easily readable and that can be adjusted more quickly than when using Linux.

### **Joining tables**

Some security-related decisions require information from different tables. SQL allows the analyst to join multiple tables together when returning data. Linux doesn’t have that same functionality; it doesn’t allow data to be connected to other information on your computer. This is more restrictive for an analyst going through security logs.

### **Best uses**

As a security analyst, it’s important to understand when you can use which tool. Although SQL has a more organized structure and allows you to join tables, this doesn’t mean that there aren’t situations that would require you to filter data in Linux.

A lot of data used in cybersecurity will be stored in a database format that works with SQL. However, other logs might be in a format that is not compatible with SQL. For instance, if the data is stored in a text file, you cannot search through it with SQL. In those cases, it is useful to know how to filter in Linux. 

## **Key takeaways**

Linux filtering focuses on managing files and directories on a system, while SQL filtering focuses on structured data manipulation within databases. To work with SQL, you can access it from multiple different interfaces, such as the Linux command line. Both SQL and Linux allow you to filter for specific data, but SQL offers the advantages of structuring the data and allowing you to join data from multiple tables.

# Queries 
# Query a database

Previously, you explored how SQL is an important tool in the world of cybersecurity and is essential when querying databases. You examined a few basic SQL queries and keywords used to extract needed information from a database. In this reading, you’ll review those basic SQL queries and learn a new keyword that will help you organize your output. You'll also learn about the Chinook database, which this course uses for queries in readings and quizzes.

## Basic SQL query

There are two essential keywords in any SQL query: SELECT and FROM. You will use these keywords every time you want to query a SQL database. Using them together helps SQL identify what data you need from a database and the table you are returning it from.

The video demonstrated this SQL query:

SELECT employee_id, device_id

FROM employees;

In readings and quizzes, this course uses a sample database called the Chinook database to run queries. The Chinook database includes data that might be created at a digital media company. A security analyst employed by this company might need to query this data.  For example, the database contains eleven tables, including an employees table, a customers table, and an invoices table. These tables include data such as names and addresses.  

As an example, you can run this query to return data from the customers table of the Chinook database:

1

2

+------------+---------------------+----------------+
| CustomerId | City                | Country        |
+------------+---------------------+----------------+
|          1 | São José dos Campos | Brazil         |
|          2 | Stuttgart           | Germany        |
|          3 | Montréal            | Canada         |
|          4 | Oslo                | Norway         |
|          5 | Prague              | Czech Republic |
|          6 | Prague              | Czech Republic |
|          7 | Vienne              | Austria        |
|          8 | Brussels            | Belgium        |
|          9 | Copenhagen          | Denmark        |
|         10 | São Paulo           | Brazil         |
|         11 | São Paulo           | Brazil         |
|         12 | Rio de Janeiro      | Brazil         |
|         13 | Brasília            | Brazil         |
|         14 | Edmonton            | Canada         |
|         15 | Vancouver           | Canada         |
|         16 | Mountain View       | USA            |
|         17 | Redmond             | USA            |
|         18 | New York            | USA            |
|         19 | Cupertino           | USA            |
|         20 | Mountain View       | USA            |
|         21 | Reno                | USA            |
|         22 | Orlando             | USA            |
|         23 | Boston              | USA            |
|         24 | Chicago             | USA            |
|         25 | Madison             | USA            |
+------------+---------------------+----------------+
(Output limit exceeded, 25 of 59 total rows shown)

### **SELECT**

The SELECT keyword indicates which columns to return. For example, you can return the customerid column from the Chinook database with

SELECT customerid

You can also select multiple columns by separating them with a comma. For example, if you want to return both the customerid and city columns, you should write SELECT customerid, city.

If you want to return all columns in a table, you can follow the SELECT keyword with an asterisk (*). The first line in the query will be SELECT *.

**Note:** Although the tables you're querying in this course are relatively small, using SELECT * may not be advisable when working with large databases and tables; in those cases, the final output may be difficult to understand and might be slow to run. 

### **FROM**

The SELECT keyword always comes with the FROM keyword. FROM indicates which table to query. To use the FROM keyword, you should write it after the SELECT keyword, often on a new line, and follow it with the name of the table you’re querying. If you want to return all columns from the customers table, you can write:

SELECT *

FROM customers;

When you want to end the query here, you put a semicolon (;) at the end to tell SQL that this is the entire query.

**Note:** Line breaks are not necessary in SQL queries, but are often used to make the query easier to understand. If you prefer, you can also write the previous query on one line as

SELECT * FROM customers;

## ORDER BY

Database tables are often very complicated, and this is where other SQL keywords come in handy. ORDER BY is an important keyword for organizing the data you extract from a table.

ORDER BY sequences the records returned by a query based on a specified column or columns. This can be in either ascending or descending order.

### **Sorting in ascending order**

To use the ORDER BY keyword, write it at the end of the query and specify a column to base the sort on. In this example, SQL will return the customerid, city, and country columns from the customers table, and the records will be sequenced by the city column:

1

2

3

The ORDER BY keyword sorts the records based on the column specified after this keyword. By default, as shown in this example, the sequence will be in ascending order. This means

- if you choose a column containing numeric data, it sorts the output from the smallest to largest. For example, if sorting on customerid, the ID numbers are sorted from smallest to largest.
    
- if the column contains alphabetic characters, such as in the example with the city column, it orders the records from the beginning of the alphabet to the end. 
    

### **Sorting in descending order**

You can also use the ORDER BY with the DESC keyword to sort in descending order. The DESC keyword is short for "descending" and tells SQL to sort numbers from largest to smallest, or alphabetically from Z to A. This can be done by following ORDER BY with the DESC keyword. For example, you can run this query to examine how the results differ when DESC is applied: 

1

2

3

Now, cities at the end of the alphabet are listed first.

### **Sorting based on multiple columns**

You can also choose multiple columns to order by. For example, you might first choose the country and then the city column. SQL then sorts the output by country, and for rows with the same country, it sorts them based on city. You can run this to explore how SQL displays this:

1

2

3

## Key takeaways

SELECT and FROM are important keywords in SQL queries. You use SELECT to indicate which columns to return and FROM to indicate which table to query. You can also include ORDER BY in your query to organize the output. These foundational SQL skills will support you as you move into more advanced queries.
![[Pasted image 20250112143112.png]]
![[Pasted image 20250112143127.png]]
# The WHERE clause and basic operators

Previously, you focused on how to refine your SQL queries by using the WHERE clause to filter results. In this reading, you’ll further explore how to use the WHERE clause, the LIKE operator and the percentage sign (%) wildcard. You’ll also be introduced to the underscore (_), another wildcard that can help you filter queries.

## How filtering helps

As a security analyst, you'll often be responsible for working with very large and complicated security logs. To find the information you need, you'll often need to use SQL to filter the logs.

In a cybersecurity context, you might use filters to find the login attempts of a specific user or all login attempts made at the time of a security issue. As another example, you might filter to find the devices that are running a specific version of an application.

## WHERE 

To create a filter in SQL, you need to use the keyword WHERE. WHERE indicates the condition for a filter.

If you needed to email employees with a title of IT Staff, you might use a query like the one in the following example. You can run this example to examine what it returns: 

1

2

3

Rather than returning all records in the employees table, this WHERE clause instructs SQL to return only those that contain 'IT Staff' in the title column. It uses the equals sign (=) operator to set this condition.

**Note:** You should place the semicolon (;) where the query ends. When you add a filter to a basic query, the semicolon is after the filter. 

## Filtering for patterns

You can also filter based on a pattern. For example, you can identify entries that start or end with a certain character or characters. Filtering for a pattern requires incorporating two more elements into your WHERE clause:

- a wildcard 
    
- the LIKE operator
    

### **Wildcards**

A **wildcard** is a special character that can be substituted with any other character. Two of the most useful wildcards are the percentage sign (%) and the underscore (_):

- The percentage sign substitutes for any number of other characters. 
    
- The underscore symbol only substitutes for one other character.
    

These wildcards can be placed after a string, before a string, or in both locations depending on the pattern you’re filtering for.

The following table includes these wildcards applied to the string 'a' and examples of what each pattern would return.

|**Pattern**|**Results that could be returned**|
|---|---|
|'a%'|apple123, art, a|
|'a_'|as, an, a7|
|'a__'|ant, add, a1c|
|'%a'|pizza, Z6ra, a|
|'_a'|ma, 1a, Ha|
|'%a%'|Again, back, a|
|'_a_'|Car, ban, ea7|

### **LIKE**

To apply wildcards to the filter, you need to use the LIKE operator instead of an equals sign (=). LIKE is used with WHERE to search for a pattern in a column. 

For instance, if you want to email employees with a title of either 'IT Staff' or 'IT Manager', you can use LIKE operator combined with the % wildcard:  

1

2

3

This query returns all records with values in the title column that start with the pattern of 'IT'. This means both 'IT Staff' and 'IT Manager' are returned.

As another example, if you want to search through the invoices table to find all customers located in states with an abbreviation of 'NY', 'NV', 'NS' or 'NT', you can use the 'N_' pattern on the state column:

1

2

3

This returns all the records with state abbreviations that follow this pattern.

## Key takeaways

Filters are important when refining what your query returns. WHERE is an essential keyword for adding a filter to your query.  You can also filter for patterns by combining the LIKE operator with the percentage sign (%) and the underscore (_) wildcards.


![[Pasted image 20250112144251.png]]![[Pasted image 20250112144311.png]]
![[Pasted image 20250112144324.png]]

# Operators for filtering dates and numbers

Previously, you examined operators like less than (<) or greater than (>) and explored how they can be used in filtering numeric and date and time data types. This reading summarizes what you learned and provides new examples of using operators in filters.

## Numbers, dates, and times in cybersecurity

Security analysts work with more than just **string data**, or data consisting of an ordered sequence of characters. 

They also frequently work with **numeric data**, or data consisting of numbers. A few examples of numeric data that you might encounter in your work as a security analyst include:

- the number of login attempts
    
- the count of a specific type of log entry
    
- the volume of data being sent from a source
    
- the volume of data being sent to a destination
    

You'll also encounter **date and time data**, or data representing a date and/or time. As a first example, logs will generally timestamp every record. Other time and date data might include:

- login dates
    
- login times
    
- dates for patches 
    
- the duration of a connection
    

## Comparison operators

In SQL, filtering numeric and date and time data often involves operators. You can use the following operators in your filters to make sure you return only the rows you need:

|**operator**|**use**|
|---|---|
|<|less than|
|>|greater than|
|=|equal to|
|<=|less than or equal to|
|>=|greater than or equal to|
|<>|not equal to|

**Note:** You can also use != as an alternative operator for not equal to.

### Incorporating operators into filters

These comparison operators are used in the WHERE clause at the end of a query. The following query uses the > operator to filter the birthdate column. You can run this query to explore its output:

1

2

3

+-----------+----------+---------------------+
| FirstName | LastName | BirthDate           |
+-----------+----------+---------------------+
| Jane      | Peacock  | 1973-08-29 00:00:00 |
| Michael   | Mitchell | 1973-07-01 00:00:00 |
| Robert    | King     | 1970-05-29 00:00:00 |
+-----------+----------+---------------------+

This query returns the first and last names of employees born after, but not on, '1970-01-01' (or January 1, 1970). If you were to use the >= operator instead, the results would also include results on exactly '1970-01-01'.

In other words, the > operator is exclusive and the >= operator is inclusive.  An **exclusive operator** is an operator that does not include the value of comparison. An **inclusive operator** is an operator that includes the value of comparison.

### **BETWEEN**

Another operator used for numeric data as well as date and time data is the BETWEEN operator. BETWEEN filters for numbers or dates within a range. For example, if you want to find the first and last names of all employees hired between January 1, 2002 and January 1, 2003, you can use the BETWEEN operator as follows:

1

2

3

+-----------+----------+---------------------+
| FirstName | LastName | HireDate            |
+-----------+----------+---------------------+
| Andrew    | Adams    | 2002-08-14 00:00:00 |
| Nancy     | Edwards  | 2002-05-01 00:00:00 |
| Jane      | Peacock  | 2002-04-01 00:00:00 |
+-----------+----------+---------------------+

**Note:** The BETWEEN operator is inclusive. This means records with a hiredate of January 1, 2002 or January 1, 2003 are included in the results of the previous query.

## Key takeaways

Operators are important when filtering numeric and date and time data. These include exclusive operators such as < and inclusive operators such as  <=. The BETWEEN operator, another inclusive operator, helps you return the data you need within a range.

# More on filters with AND, OR, and NOT

Previously, you explored how to add filters containing the AND, OR, and NOT operators to your SQL queries. In this reading, you'll continue to explore how these operators can help you refine your queries.

## Logical operators

AND, OR, and NOT allow you to filter your queries to return the specific information that will help you in your work as a security analyst. They are all considered logical operators.

### AND

First, AND is used to filter on two conditions. AND specifies that both conditions must be met simultaneously. 

As an example, a cybersecurity concern might affect only those customer accounts that meet both the condition of being handled by a support representative with an ID of 5 and the condition of being located in the USA. To find the names and emails of those specific customers, you should place the two conditions on either side of the AND operator in the WHERE clause:

1

2

3

+-----------+----------+-------------------------+---------+--------------+
| FirstName | LastName | Email                   | Country | SupportRepId |
+-----------+----------+-------------------------+---------+--------------+
| Jack      | Smith    | jacksmith@microsoft.com | USA     |            5 |
| Kathy     | Chase    | kachase@hotmail.com     | USA     |            5 |
| Victor    | Stevens  | vstevens@yahoo.com      | USA     |            5 |
| Julia     | Barnett  | jubarnett@gmail.com     | USA     |            5 |
+-----------+----------+-------------------------+---------+--------------+

Running this query returns four rows of information about the customers. You can use this information to contact them about the security concern.

### OR

The OR operator also connects two conditions, but OR specifies that either condition can be met. It returns results where the first condition, the second condition, or both are met.

For example, if you are responsible for finding all customers who are either in the USA or Canada so that you can communicate information about a security update, you can use an OR operator to find all the needed records. As the following query demonstrates, you should place the two conditions on either side of the OR operator in the WHERE clause:

1

2

3

+-----------+------------+--------------------------+---------+
| FirstName | LastName   | Email                    | Country |
+-----------+------------+--------------------------+---------+
| François  | Tremblay   | ftremblay@gmail.com      | Canada  |
| Mark      | Philips    | mphilips12@shaw.ca       | Canada  |
| Jennifer  | Peterson   | jenniferp@rogers.ca      | Canada  |
| Frank     | Harris     | fharris@google.com       | USA     |
| Jack      | Smith      | jacksmith@microsoft.com  | USA     |
| Michelle  | Brooks     | michelleb@aol.com        | USA     |
| Tim       | Goyer      | tgoyer@apple.com         | USA     |
| Dan       | Miller     | dmiller@comcast.com      | USA     |
| Kathy     | Chase      | kachase@hotmail.com      | USA     |
| Heather   | Leacock    | hleacock@gmail.com       | USA     |
| John      | Gordon     | johngordon22@yahoo.com   | USA     |
| Frank     | Ralston    | fralston@gmail.com       | USA     |
| Victor    | Stevens    | vstevens@yahoo.com       | USA     |
| Richard   | Cunningham | ricunningham@hotmail.com | USA     |
| Patrick   | Gray       | patrick.gray@aol.com     | USA     |
| Julia     | Barnett    | jubarnett@gmail.com      | USA     |
| Robert    | Brown      | robbrown@shaw.ca         | Canada  |
| Edward    | Francis    | edfrancis@yachoo.ca      | Canada  |
| Martha    | Silk       | marthasilk@gmail.com     | Canada  |
| Aaron     | Mitchell   | aaronmitchell@yahoo.ca   | Canada  |
| Ellie     | Sullivan   | ellie.sullivan@shaw.ca   | Canada  |
+-----------+------------+--------------------------+---------+

The query returns all customers in either the US or Canada.

**Note:** Even if both conditions are based on the same column, you need to write out both full conditions. For instance, the query in the previous example contains the filter WHERE country = 'Canada' OR country = 'USA'.

### NOT

Unlike the previous two operators, the NOT operator only works on a single condition, and not on multiple ones. The NOT operator negates a condition. This means that SQL returns all records that don’t match the condition specified in the query. 

For example, if a cybersecurity issue doesn't affect customers in the USA but might affect those in other countries, you can return all customers who are not in the USA. This would be more efficient than creating individual conditions for all of the other countries. To use the NOT operator for this task, write the following query and place NOT directly after WHERE:

1

2

3

+-----------+-------------+-------------------------------+----------------+
| FirstName | LastName    | Email                         | Country        |
+-----------+-------------+-------------------------------+----------------+
| Luís      | Gonçalves   | luisg@embraer.com.br          | Brazil         |
| Leonie    | Köhler      | leonekohler@surfeu.de         | Germany        |
| François  | Tremblay    | ftremblay@gmail.com           | Canada         |
| Bjørn     | Hansen      | bjorn.hansen@yahoo.no         | Norway         |
| František | Wichterlová | frantisekw@jetbrains.com      | Czech Republic |
| Helena    | Holý        | hholy@gmail.com               | Czech Republic |
| Astrid    | Gruber      | astrid.gruber@apple.at        | Austria        |
| Daan      | Peeters     | daan_peeters@apple.be         | Belgium        |
| Kara      | Nielsen     | kara.nielsen@jubii.dk         | Denmark        |
| Eduardo   | Martins     | eduardo@woodstock.com.br      | Brazil         |
| Alexandre | Rocha       | alero@uol.com.br              | Brazil         |
| Roberto   | Almeida     | roberto.almeida@riotur.gov.br | Brazil         |
| Fernanda  | Ramos       | fernadaramos4@uol.com.br      | Brazil         |
| Mark      | Philips     | mphilips12@shaw.ca            | Canada         |
| Jennifer  | Peterson    | jenniferp@rogers.ca           | Canada         |
| Robert    | Brown       | robbrown@shaw.ca              | Canada         |
| Edward    | Francis     | edfrancis@yachoo.ca           | Canada         |
| Martha    | Silk        | marthasilk@gmail.com          | Canada         |
| Aaron     | Mitchell    | aaronmitchell@yahoo.ca        | Canada         |
| Ellie     | Sullivan    | ellie.sullivan@shaw.ca        | Canada         |
| João      | Fernandes   | jfernandes@yahoo.pt           | Portugal       |
| Madalena  | Sampaio     | masampaio@sapo.pt             | Portugal       |
| Hannah    | Schneider   | hannah.schneider@yahoo.de     | Germany        |
| Fynn      | Zimmermann  | fzimmermann@yahoo.de          | Germany        |
| Niklas    | Schröder    | nschroder@surfeu.de           | Germany        |
+-----------+-------------+-------------------------------+----------------+
(Output limit exceeded, 25 of 46 total rows shown)

SQL returns every entry where the customers are not from the USA.

**Pro tip:** Another way of finding values that are not equal to a certain value is by using the <> operator or the != operator. For example, WHERE country <> 'USA' and WHERE country != 'USA' are the same filters as WHERE NOT country = 'USA'.

## Combining logical operators

Logical operators can be combined in filters. For example, if you know that both the USA and Canada are not affected by a cybersecurity issue, you can combine operators to return customers in all countries besides these two. In the following query, NOT is placed before the first condition, it's joined to a second condition with AND, and then NOT is also placed before that second condition. You can run it to explore what it returns:

1

2

3

+-----------+-------------+-------------------------------+----------------+
| FirstName | LastName    | Email                         | Country        |
+-----------+-------------+-------------------------------+----------------+
| Luís      | Gonçalves   | luisg@embraer.com.br          | Brazil         |
| Leonie    | Köhler      | leonekohler@surfeu.de         | Germany        |
| Bjørn     | Hansen      | bjorn.hansen@yahoo.no         | Norway         |
| František | Wichterlová | frantisekw@jetbrains.com      | Czech Republic |
| Helena    | Holý        | hholy@gmail.com               | Czech Republic |
| Astrid    | Gruber      | astrid.gruber@apple.at        | Austria        |
| Daan      | Peeters     | daan_peeters@apple.be         | Belgium        |
| Kara      | Nielsen     | kara.nielsen@jubii.dk         | Denmark        |
| Eduardo   | Martins     | eduardo@woodstock.com.br      | Brazil         |
| Alexandre | Rocha       | alero@uol.com.br              | Brazil         |
| Roberto   | Almeida     | roberto.almeida@riotur.gov.br | Brazil         |
| Fernanda  | Ramos       | fernadaramos4@uol.com.br      | Brazil         |
| João      | Fernandes   | jfernandes@yahoo.pt           | Portugal       |
| Madalena  | Sampaio     | masampaio@sapo.pt             | Portugal       |
| Hannah    | Schneider   | hannah.schneider@yahoo.de     | Germany        |
| Fynn      | Zimmermann  | fzimmermann@yahoo.de          | Germany        |
| Niklas    | Schröder    | nschroder@surfeu.de           | Germany        |
| Camille   | Bernard     | camille.bernard@yahoo.fr      | France         |
| Dominique | Lefebvre    | dominiquelefebvre@gmail.com   | France         |
| Marc      | Dubois      | marc.dubois@hotmail.com       | France         |
| Wyatt     | Girard      | wyatt.girard@yahoo.fr         | France         |
| Isabelle  | Mercier     | isabelle_mercier@apple.fr     | France         |
| Terhi     | Hämäläinen  | terhi.hamalainen@apple.fi     | Finland        |
| Ladislav  | Kovács      | ladislav_kovacs@apple.hu      | Hungary        |
| Hugh      | O'Reilly    | hughoreilly@apple.ie          | Ireland        |
+-----------+-------------+-------------------------------+----------------+
(Output limit exceeded, 25 of 38 total rows shown)

## Key takeaways

Logical operators allow you to create more specific filters that target the security-related information you need. The AND operator requires two conditions to be true simultaneously, the OR operator requires either one or both conditions to be true, and the NOT operator negates a condition. Logical operators can be combined together to create even more specific queries.

# SQL joins
![[Pasted image 20250112154146.png]]
![[Pasted image 20250112154207.png]]
![[Pasted image 20250112154242.png]]

![[Pasted image 20250112154430.png]]
![[Pasted image 20250112154437.png]]
![[Pasted image 20250112154452.png]]
![[Pasted image 20250112154502.png]]![[Pasted image 20250112154507.png]]
![[Pasted image 20250112154533.png]]
 ![[Pasted image 20250112154540.png]]
 # Compare types of joins

Previously, you explored SQL joins and how to use them to join data from multiple tables when these tables share a common column. You also examined how there are different types of joins, and each of them returns different rows from the tables being joined. In this reading, you'll review these concepts and more closely analyze the syntax needed for each type of join.

## Inner joins

The first type of join that you might perform is an inner join. INNER JOIN returns rows matching on a specified column that exists in more than one table.

![Venn diagram with two circles labeled "left table" and "right table". The intersection is highlighted.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/9y5ZKSySQTuS5RQ-MJLXrA_6b756cb30b9442c8ae576607a6ab3ff1_CS_R-080_Inner-joins.png?expiry=1736812800000&hmac=arILok04SmyhY36DI8CrtuLlIq4jikVQcvRn2UK1Wa8)

It only returns the rows where there is a match, but like other types of joins, it returns all specified columns from all joined tables. For example, if the query joins two tables with SELECT *, all columns in both of the tables are returned.

**Note:** If a column exists in both of the tables, it is returned twice when SELECT * is used.

### The syntax of an inner join

To write a query using INNER JOIN, you can use the following syntax:

SELECT *

FROM employees

INNER JOIN machines ON employees.device_id = machines.device_id;

You must specify the two tables to join by including the first or left table after FROM and the second or right table after INNER JOIN.

After the name of the right table, use the ON keyword and the = operator to indicate the column you are joining the tables on. It's important that you specify both the table and column names in this portion of the join by placing a period (.) between the table and the column.  

In addition to selecting all columns, you can select only certain columns.  For example, if you only want the join to return the username, operating_system and device_id columns, you can write this query:

SELECT username, operating_system, employees.device_id

FROM  employees

INNER JOIN machines ON employees.device_id = machines.device_id;

**Note**: In the example query, username and operating_system only appear in one of the two tables, so they are written with just the column name. On the other hand, because device_id appears in both tables, it's necessary to indicate which one to return by specifying both the table and column name (employees.device_id).

## Outer joins

Outer joins expand what is returned from a join. Each type of outer join returns all rows from either one table or both tables.

### Left joins

When joining two tables, LEFT JOIN returns all the records of the first table, but only returns rows of the second table that match on a specified column. 

![Venn diagram with two circles labeled "left table" and "right table". The left circle and the intersection are highlighted.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/GsYCwSiOSMmymUqPUAQJ5w_5beed7e470c546fca088a83dfd9465f1_CS_R-080_Left-joins.png?expiry=1736812800000&hmac=mokV84PIW2C7kzc4FiVL_hAlPs-3LgLv067igbCzfjY)

The syntax for using LEFT JOIN is demonstrated in the following query:

SELECT *

FROM employees

LEFT JOIN machines ON employees.device_id = machines.device_id;

As with all joins, you should specify the first or left table as the table that comes after FROM and the second or right table as the table that comes after LEFT JOIN. In the example query, because employees is the left table, all of its records are returned. Only records that match on the device_id column are returned from the right table, machines. 

### Right joins

When joining two tables, RIGHT JOIN returns all of the records of the second table, but only returns rows from the first table that match on a specified column.

![Venn diagram with two circles labeled "left table" and "right table". The right circle and the intersection are highlighted.](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/YHXRMOLiQheppUjthmM5yQ_cfb18a8315e34357bd1299f7eefafcf1_CS_R-080_Right-joins.png?expiry=1736812800000&hmac=mbdAdv3_dhaKanuscLVYPsRSN5j-CwAb0tkrcbhv21A)

The following query demonstrates the syntax for RIGHT JOIN:

SELECT *

FROM employees

RIGHT JOIN machines ON employees.device_id = machines.device_id;

RIGHT JOIN has the same syntax as LEFT JOIN, with the only difference being the keyword RIGHT JOIN instructs SQL to produce different output. The query returns all records from machines, which is the second or right table. Only matching records are returned from employees, which is the first or left table.

**Note:**  You can use LEFT JOIN and RIGHT JOIN and return the exact same results if you use the tables in reverse order. The following RIGHT JOIN query returns the exact same result as the LEFT JOIN query demonstrated in the previous section:

SELECT *

FROM machines

RIGHT JOIN employees ON employees.device_id = machines.device_id;

All that you have to do is switch the order of the tables that appear before and after the keyword used for the join, and you will have swapped the left and right tables.

### Full outer joins 

FULL OUTER JOIN returns all records from both tables. You can think of it as a way of completely merging two tables.

![Venn diagram with two circles labeled "left table" and "right table". Both circles are highlighted](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/oRzF__GaTqSGMmUqXKbSrQ_92db9841a00244c2aa214e60bb07f1f1_CS_R-080_FULL-OUTER-JOIN.png?expiry=1736812800000&hmac=hQbpQBG5kKAQkOtHjjxqZT16MYA3si6JKI6ywog4aDo)

You can review the syntax for using FULL OUTER JOIN in the following query:

SELECT *

FROM employees

FULL OUTER JOIN machines ON employees.device_id = machines.device_id;

The results of a FULL OUTER JOIN query include all records from both tables. Similar to INNER JOIN, the order of tables does not change the results of the query.

## Key takeaways

When working in SQL, there are multiple ways to join tables.  All joins return the records that match on a specified column. INNER JOIN will return only these records. Outer joins also return all other records from one or both of the tables. LEFT JOIN returns all records from the first or left table, RIGHT JOIN returns all records from the second or right table, and FULL OUTER JOIN returns all records from both tables.

# Continuous learning in SQL

You've explored a lot about SQL, including applying filters to SQL queries and joining multiple tables together in a query.  There's still more that you can do with SQL. This reading will explore an example of something new you can add to your SQL toolbox: aggregate functions. You'll then focus on how you can continue learning about this and other SQL topics on your own.

## Aggregate functions

In SQL, **aggregate functions** are functions that perform a calculation over multiple data points and return the result of the calculation. The actual data is not returned. 

There are various aggregate functions that perform different calculations:

- COUNT returns a single number that represents the number of rows returned from your query.
    
- AVG returns a single number that represents the average of the numerical data in a column.
    
- SUM returns a single number that represents the sum of the numerical data in a column. 
    

### **Aggregate function syntax**

To use an aggregate function, place the keyword for it after the SELECT keyword, and then in parentheses, indicate the column you want to perform the calculation on.

For example, when working with the customers table, you can use aggregate functions to summarize important information about the table. If you want to find out how many customers there are in total, you can use the COUNT function on any column, and SQL will return the total number of records, excluding NULL values. You can run this query and explore its output:

1

2

+------------------+
| COUNT(firstname) |
+------------------+
|               59 |
+------------------+

The result is a table with one column titled COUNT(firstname) and one row that indicates the count.

If you want to find the number of customers from a specific country, you can add a filter to your query:

1

2

3

+------------------+
| COUNT(firstname) |
+------------------+
|               13 |
+------------------+

With this filter, the count is lower because it only includes the records where the country column contains a value of 'USA'.

There are a lot of other aggregate functions in SQL. The syntax of placing them after SELECT is exactly the same as the COUNT function.

## Continuing to learn SQL

SQL is a widely used querying language, with many more keywords and applications. You can continue to learn more about aggregate functions and other aspects of using SQL on your own.

Most importantly, approach new tasks with curiosity and a willingness to find new ways to apply SQL to your work as a security analyst. Identify the data results that you need and try to use SQL to obtain these results.

Fortunately, SQL is one of the most important tools for working with databases and analyzing data, so you'll find a lot of support in trying to learn SQL online. First, try searching for the concepts you've already learned and practiced to find resources that have accurate easy-to-follow explanations. When you identify these resources, you can use them to extend your knowledge.

Continuing your practical experience with SQL is also important. You can also search for new databases that allow you to perform SQL queries using what you've learned.

## Key takeaways

Aggregate functions like COUNT, SUM, and AVG allow you to work with SQL in new ways. There are many other additional aspects of SQL that could be useful to you as an analyst. By continuing to explore SQL on your own, you can expand the ways you can apply SQL in a cybersecurity context.

# Reference guide: SQL

The SQL reference guide contains keywords for SQL queries. Security analysts can use these keywords to query databases and find data to support security-related decisions. The reference guide is divided into four different categories of SQL keywords for security-related tasks: 

- Query a database
    
- Apply filters to SQL queries
    
- Join tables
    
- Perform calculations
    

Within each category, commands are organized alphabetically.

## Access and save the guide

You can save a copy of this guide for future reference. You can use it as a resource for additional practice or in your future professional projects. 

To access a downloadable version of this course item, click the following link and select _Use Template_. 

[Reference guide: SQL](https://docs.google.com/document/d/1QVfrtp4QywbvQ5ALupN7-gKNrXI9yrYDv6PyCwWVAYg/template/preview)

OR

If you don’t have a Google account, you can download the item directly from the following attachment.