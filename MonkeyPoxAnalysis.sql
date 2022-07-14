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




