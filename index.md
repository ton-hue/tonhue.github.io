# Hi, I'm Tonio Thurman

* Email: tonio.thurman@outlook.com
  

This website contains projects/analysis in various software. 

-----

* Languages & Tools: 

<img src="https://rstudio.com/wp-content/uploads/2018/10/RStudio-Logo-Flat.png" width="200" height="100" /><img src="https://logos-world.net/wp-content/uploads/2021/10/Tableau-Logo.png" width="200" height="100" /><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/Python_logo_and_wordmark.svg/2560px-Python_logo_and_wordmark.svg.png" width="200" height="100" /><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/87/Sql_data_base_with_logo.png/800px-Sql_data_base_with_logo.png" width="200" height="100" /><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/306px-ISO_C%2B%2B_Logo.svg.png" width="100" height="100" /><img src="https://w7.pngwing.com/pngs/729/271/png-transparent-splunk-app-logo-tech-companies.png" width="100" height="100" />

* Certifications: 

<img src="https://images.credly.com/images/d41de2b7-cbc2-47ec-bcf1-ebecbe83872f/GCC_badge_DA_1000x1000.png" width="300" height="400" />

-----

## **MonkeyPox Data Tableau Image Creation - 5/6/2022 - 7/7/2022** 
Using SQL I wrote a few queries that would show the most confirmed cases of monkeypox by country and join two tables together for daily case confirmation analysis. The data was downloaded from Kaggle.com titled "Monkeypox Dataset (Daily Updated)" containing 3 small tables of data. I then copied and pasted the query outcomes from Microsoft SQL Server into Excel and imported into Tableau public to create the visual below. 5/6/2022 - 7/7/2022

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
## Monkey Pox Tableau Creation - Highest Cases Per Country 5/6/2022 - 7/7/2022
-----

<div class='tableauPlaceholder' id='viz1658056140852' style='position: relative'><noscript><a href='#'><img alt='Confirmed Case Count by Country ' src='https:&#47;&#47;public.tableau.com&#47;static&#47;images&#47;Mo&#47;MonkeyPoxExample&#47;Sheet1&#47;1_rss.png' style='border: none' /></a></noscript><object class='tableauViz'  style='display:none;'><param name='host_url' value='https%3A%2F%2Fpublic.tableau.com%2F' /> <param name='embed_code_version' value='3' /> <param name='site_root' value='' /><param name='name' value='MonkeyPoxExample&#47;Sheet1' /><param name='tabs' value='no' /><param name='toolbar' value='yes' /><param name='static_image' value='https:&#47;&#47;public.tableau.com&#47;static&#47;images&#47;Mo&#47;MonkeyPoxExample&#47;Sheet1&#47;1.png' /> <param name='animate_transition' value='yes' /><param name='display_static_image' value='yes' /><param name='display_spinner' value='yes' /><param name='display_overlay' value='yes' /><param name='display_count' value='yes' /><param name='language' value='en-US' /></object></div>   <script type='text/javascript'>                    var divElement = document.getElementById('viz1658056140852');                    var vizElement = divElement.getElementsByTagName('object')[0];                    vizElement.style.width='100%';vizElement.style.height=(divElement.offsetWidth*0.75)+'px';                    var scriptElement = document.createElement('script');                    scriptElement.src = 'https://public.tableau.com/javascripts/api/viz_v1.js';                    vizElement.parentNode.insertBefore(scriptElement, vizElement); </script>
      

-----






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

Using RStudio I analyzed a Fashion Trend Dataset from Kaggle Titled "Fashion Reliance Trends". The data contained one table that I analyzed to make
sales suggestions for the company. I utilzed ggplot to create trends that I found while analyzing the data. My Orginal file can be found here🖥️



## RStudio Code with Notation

```markdown
#I imported the fashion trends csv file and reviewing the head/columns. 
head(Reliance.Trends.Fashion)

#Next, I am installing janitor library to clean the 
#data before doing my analysis.Using clean_names first, I wanted
#to ensure column names are tidy.
library(janitor)
datasales1 <- clean_names(Reliance.Trends.Fashion)
datasales1

#Next, I used remove_empty from the janitor library.
#There were no empty columns but wanted to ensure there
#were no empty rows. 

datasales2 <- remove_empty(datasales1, which = c("rows"), quiet = FALSE)

#Since the dataset does not have dates/sale_id on items I will be skipping
#using the distinct feature to remove any duplicated items. 

#Using the hmisc library I was able to review frequency, highest, 
#and lowest, of each column for my analysis. 
library(Hmisc)
describe(Reliance.Trends.Fashion)

library(ggplot2)
str(Reliance.Trends.Fashion)

#ggplot would not show when tryingg to create bargraph so i reinstalled ggplot2
install.packages("ggplot2", dependencies = TRUE)

#Wanted to make a visual of most popular clothing category by gender using ggplot.
ggplot(Reliance.Trends.Fashion, aes(x=Category, fill=Category_by_gender)) +
  geom_bar(position = "dodge" )

#Used tabyl to count brands to see which ones are the most popular
library(janitor)
tabyl(Reliance.Trends.Fashion, Brand)

#Saved table under PopBrand 
PopBrand <- tabyl(Reliance.Trends.Fashion, Brand)  
```
-----
## RStudio Bar Chart | Gender & Clothing Category
I created this to identify which clothing category was popular amoung each gender. This information can be used for the
company to know which category to restock to ensure customer satisfaction for both males and females.

<a href="https://ibb.co/nLq1TnX"><img src="https://i.ibb.co/DRPMN8B/Rplotmenwom.png" alt="Rplotmenwom" border="0"></a>
-----
## Most popular fashion brands Excel Chart

I put the most popular brands in Excel for analysis and file can be found <a href="https://github.com/tthurman-data/tthurman_data.github.io/blob/gh-pages/Book%202(2).xlsx"> here. </a> 

-----
## Executive Summary of Fashion Trend Analysis
<a href="https://ibb.co/6HNWNdX"><img src="https://i.ibb.co/QPXKX5D/find.png" alt="find" border="0"></a>
