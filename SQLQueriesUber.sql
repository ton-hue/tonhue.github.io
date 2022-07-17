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




