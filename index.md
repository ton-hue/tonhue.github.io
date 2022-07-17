# Hi :wave:, I'm Tonio Thurman

* Email: exp61964@outlook.com
* LinkedIn:  

This website contains projects and skills to showcase knowledge in data analysis/science.  
-----
* Languages & Tools: 

<img src="https://rstudio.com/wp-content/uploads/2018/10/RStudio-Logo-Flat.png" width="200" height="100" /><img src="https://logos-world.net/wp-content/uploads/2021/10/Tableau-Logo.png" width="200" height="100" /><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/Python_logo_and_wordmark.svg/2560px-Python_logo_and_wordmark.svg.png" width="200" height="100" /><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/Sql_data_base_with_logo.png/800px-Sql_data_base_with_logo.png" width="200" height="100" />

* Certifications: 

<img src="https://images.credly.com/images/d41de2b7-cbc2-47ec-bcf1-ebecbe83872f/GCC_badge_DA_1000x1000.png" width="300" height="400" />

-----

## **MonkeyPox SQL Queries & Tableau Image Creation** 
Using SQL I wrote a few queries that would show the most confirmed cases of monkeypox by country and join two tables together for daily case confirmation analysis. The data was downloaded from Kaggle.com titled "Monkeypox Dataset (Daily Updated)" containing 3 small tables of data. I then copied and pasted the query outcomes from Microsoft SQL Server into Excel and imported into Tableau public to create the visual below. 

# Queries
-----
```
Select *
From PortfolioProject1.dbo.Daily_Country_Wise_Confirmed_Cases

 --After reviewing the given Monkeypox data from Kaggle I found that the confirmed cases in the csv file had decimals all ending with '.0' that would not work with the desc command. 
 --I used max float to ensure the maximum value of and the data would show the count in the correct way using desc.


Select Country, MAX(cast(Confirmed_Cases as float)) as ConfirmedCaseCount
From PortfolioProject1.dbo.Monkey_Pox_Cases_Worldwide
group by Country
order by ConfirmedCaseCount desc

--Next I want to compare the confirmed cases with daily confirmed cases to analyze the growth in each country. Using a join query I will view data from the 2  monkeypox tables.

Select * 
From PortfolioProject1.dbo.Daily_Country_Wise_Confirmed_Cases Daily
Join PortfolioProject1.dbo.Monkey_Pox_Cases_Worldwide World
On Daily.Country = World.Country

--Spain, Germany, England and US have the highest next day cases reported in a month time frame given. For example using Spain, on 6-29 there where 0 cases reported and on 6-30 there were 396 reported. 

```

-----
## Monkey Pox Tableau Creation - Highest Cases Per Country 
-----

<div class='tableauPlaceholder' id='viz1657782122372' style='position: relative'><noscript><a href='#'><img alt='Confirmed Case Count by Country ' src='https:&#47;&#47;public.tableau.com&#47;static&#47;images&#47;Mo&#47;MonkeyPoxExample&#47;Sheet1&#47;1_rss.png' style='border: none' /></a></noscript><object class='tableauViz'  style='display:none;'><param name='host_url' value='https%3A%2F%2Fpublic.tableau.com%2F' /> <param name='embed_code_version' value='3' /> <param name='site_root' value='' /><param name='name' value='MonkeyPoxExample&#47;Sheet1' /><param name='tabs' value='no' /><param name='toolbar' value='yes' /><param name='static_image' value='https:&#47;&#47;public.tableau.com&#47;static&#47;images&#47;Mo&#47;MonkeyPoxExample&#47;Sheet1&#47;1.png' /> <param name='animate_transition' value='yes' /><param name='display_static_image' value='yes' /><param name='display_spinner' value='yes' /><param name='display_overlay' value='yes' /><param name='display_count' value='yes' /><param name='language' value='en-US' /></object></div>                




------


------







## **Cleaning In SQL**
-----
In this section I wrote basic cleaning queries in Microsoft SQL Server using the "uber-raw-data-janjune-15" table from the data called "Uber Pickups in New York City" downloaded from Kaggle.com. Below is the notated queries used. <a href="https://www.kaggle.com/datasets/fivethirtyeight/uber-pickups-in-new-york-city"> Here </a> is the path to the Uber data from Kaggle. 

-----
<img src="https://149695847.v2.pressablecdn.com/wp-content/uploads/2020/09/Data-Cleaner.png" width="600" height="500" />

```
--Selecting all Uber data to examine what needs to be cleaned.

Select *
FROM [PortfolioProject1].[dbo].[uber-raw-data-janjune-15]

-- I noticed a good amount of Affiliated base numbers are missing, the best option may be to use Hot Deck imputation. By choosing another trip that was similar in route to input
-- in the blank Affiliated base number spaces could better the analysis instead of blank values. 

Select *
FROM [PortfolioProject1].[dbo].[uber-raw-data-janjune-15]
Where Affiliated_base_num = ''

--Since using hot deck imputation requires more analysis on the data, I will input null for now into the blank values to be updated after hot deck implementation. 

update [PortfolioProject1].[dbo].[uber-raw-data-janjune-15] 
set Affiliated_base_num = 'NULL'
where Affiliated_base_num = ''

Select *
From [PortfolioProject1].[dbo].[uber-raw-data-janjune-15]

--Next I noticed the uber data combined the date and time under Pickup_Date. So I want to create a query that will give the time a new column. 
Select Pickup_date
From [PortfolioProject1].[dbo].[uber-raw-data-janjune-15]

Alter Table [PortfolioProject1].[dbo].[uber-raw-data-janjune-15]
Add Pickup_Time Nvarchar(255);

Update [PortfolioProject1].[dbo].[uber-raw-data-janjune-15]
Set Pickup_Time = SUBSTRING(Pickup_Date, 12, charindex('12', Pickup_Date) +8) 

--Lastly, I wanted to ensure there were no messy strings in the uber data. I wrote a trim query for all columns in the table. 

Select trim(Dispatching_base_num), (Pickup_date), (Affiliated_base_num), (locationID), (Pickup_Time)
From [PortfolioProject1].[dbo].[uber-raw-data-janjune-15]


```
------



## **Analysis Project in R**

<img src="images\luke-chesser-JKUTrJ4vK00-unsplash.jpg">
This section contains the artifact and enhancement. The artifact is a creation of queries and a dashboard utilizing python to display information from MongoDB. My enhancement showcased using C++ with MongoDB to display information from the same table. The enhancement is showcasing my skills in using C++ with MongoDB. 🖥️

### Original Files

<a href="https://github.com/ton-hue/tonhue.github.io/tree/gh-pages/Database/Original%20Artifact_CS%20340"> Here </a> is the path to the orginal artifact which is the original CS 340 files in github. 

### Conversion Enhancement Files

<a href="https://github.com/ton-hue/tonhue.github.io/tree/gh-pages/Database"> Here </a> is the Changes made to the source code above, demonstrating my skills in MongoDB with C++. 

## MongoDB Conversion from Python to C++ Skill Narrative

```markdown
-The artifact is my CS 340 Project which used python to connect with mongodb using queries to display information. We utilized the virtual machine Jupiter notebook to write queries that would display information from the database in MongoDB. We then created a dashboard to display information from mongodb as well. This project was done early 2022 I believe and contained multiple files that referenced each other.
-I selected this enhancement to get a insight of how mongo databases is used with C++, using mongodb with python was fun to learn and genuinely interesting. I thought learning ways to enhance this artifact would provide knowledge I could use in the professional setting. The components that showcased my skills were applying C++ concepts already known to the project for the main.cpp file. Having knowledge of C++ and Databases allowed me to create the main file with ease. The artifact was improved by using C++ instead of python to connect to the database and write code/queries mirroing the artifact in python.
-I met the  CS objectives for this project. The main.cpp file met objectives as far as connecting to the mongodb and by choosing to use docker files. By utilizing docker files this kept the project organized for the queries to be ran with the C++. Showcasing decision making through organizational concepts allowed the project to not get overwhelming. This option also mitigate design flaws allowing the C++ MongoDB project to have quality.  The docker file took the place of the Jupiter notebook as far as running queries. The setup is different and uses  different commands in the text file.
-The process of enhancement started off straight forward, I used a cpp compiler to start the conversion. I reviewed the mongodb website to see which libraries needed to be included. Next I utilized the dbclientconnection from the website as well to connect to the port number. Then I created code to reference when connecting to the database using the try method in c++. And a catch statement for dbexception. After more research I learned I would use a docker file in the place of the Jupiter notebook to run commands/queries. I then used the docker file reference page to code the commands for c++. I learned some commands from the docker reference page and is still learning the process of the c++ query of the enhancement. -
```
