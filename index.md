#Hi I'm Tonio Thurman

*Email: exp61964@outlook.com
*LinkedIn:  

This website contains projects complete to showcase data science skills.  



-----

## **MonkeyPox SQL Queries & Tableau Image Creation** 
Using SQL I utilized a few queries that would show the most confirmed cases of monkeypox by country and join two tables together for analysis. The data was downloaded from Kaggle containing 3 small tables of data. I then copy and pasted the query outcomes from Microsoft SQL server into excel and imported into tableau public to create a visual. 

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

-----

<div class='tableauPlaceholder' id='viz1657782122372' style='position: relative'><noscript><a href='#'><img alt='Confirmed Case Count by Country ' src='https:&#47;&#47;public.tableau.com&#47;static&#47;images&#47;Mo&#47;MonkeyPoxExample&#47;Sheet1&#47;1_rss.png' style='border: none' /></a></noscript><object class='tableauViz'  style='display:none;'><param name='host_url' value='https%3A%2F%2Fpublic.tableau.com%2F' /> <param name='embed_code_version' value='3' /> <param name='site_root' value='' /><param name='name' value='MonkeyPoxExample&#47;Sheet1' /><param name='tabs' value='no' /><param name='toolbar' value='yes' /><param name='static_image' value='https:&#47;&#47;public.tableau.com&#47;static&#47;images&#47;Mo&#47;MonkeyPoxExample&#47;Sheet1&#47;1.png' /> <param name='animate_transition' value='yes' /><param name='display_static_image' value='yes' /><param name='display_spinner' value='yes' /><param name='display_overlay' value='yes' /><param name='display_count' value='yes' /><param name='language' value='en-US' /></object></div>                




------


------







## **Cleaning In SQL**

<img src="images\alpridephoto-nuz3rK5iiKg-unsplash.jpg">
The next section contains the artifact and enhancement as well. The artifact is a bidding program made in CS 260 containing multiple files, such ass the C++ file and CSV file to read the data. I created a removal algorithm for the program allowing the user to input the lowest bid to be removed. This section is showcasing my skill in algorithm enhancement. 🖥️

------

### Original Files

<a href="https://github.com/ton-hue/tonhue.github.io/tree/gh-pages/Algorithms/Original%20Artifact_CS%20260"> Here </a> is the path to the orginal artifact which is the original CS 260 files in github. 

### Algorithm Enhancement File

<a href="https://github.com/ton-hue/tonhue.github.io/blob/6fbeb242d0b911318360e573646f9409982b84d1/Algorithms/SourceandRemovalAlgorithmFinal.cpp"> Here </a> is the Changes made to the source code above, demonstrating my skills in algorithms with a removal enhancement. 

------

## Removal Algorithm Skill Narrative

```
-The artifact is my cs 260 project where we created a bidding program using algorithms and data structures. I believe this project was made in 2020 which consisted of different milestones for completion. For the artifact details, I wanted to add a feature using a remove algorithm. This allows the seller/user to remove bids that were low or useless. After reviewing the bids the seller is then allowed to enter a bid then the loop would delete it from the program. 
-I wanted to include this choice into my eportfolio as this option shows skill by improving source code and knowledge in algorithms and data structures. I found this option interesting as it allowed me take a step back to review the source code and brainstorm on how to make the software better through algorithms. Specifically, the skills that stood out during this project were attention in detail and algorithms. The artifact was simply improved by making a new loop to remove old bids inputted by the user. This keeps the bidding up to date and current, removing the outdated numbers shown. 
-For this section of the eportfolio I  meet the objectives I planned to. My enhancement was a success and fits perfectly with the source code. I evaluated the source code allowing me to design the perfect algorithm for removing bids. By utilizing great algorithmic principles I was able to enhancement the source code providing a solution that could be used in the workforce. 
-The process for enhancement was first reviewing the source code from the cs 260 project. This allowed to refresh my memory on the project and find specifically what I wanted to improve as far as algorithms and data structures. I then compared the program to popular bidding programs (such as eBay etc.) to see what made the popular software successful. I then came to a conclusion that having different components for each part of the bidding and selling process was why they were successful. So I then came up with a plan to create a page for the program to remove bids on the seller end. I then performed a simple removal algorithm loop that would first display the bids, then allow the seller to enter the bids they want to delete then start the removal loop. The challenges I faced were in the beginning of the process, not knowing what to improve on the cs 260 project. I reviewed the code plenty of times but couldn’t think of anything. After comparing the program to a real business software, I was able to think of ways to expand the source code. 

```




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
