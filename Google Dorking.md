https://www.exploit-db.com/google-hacking-database 

Name | Function
--------- | ---------
intitle | Looks for the search terms in the title
allintitle | Looks for the search terms only in the title and nowhere else in the document 
inurl | Looks through the URL (the address) for the search terms
allinurl | Similar to allintitle, looks only in the URL for the search terms
filetype | You provide the file type and search terms. All results have that filetype.
allintext | The search will not look at the URL and just in the text.
site | Narrow your search to a particular site. You have to provide the site as well as search terms.
link | Searches for links to pages
inanchor | This search will look in anchor tags only
numrange | Searches for a number
daterange | Results will be within a range of dates, as specified
author | Searches Google Groups for a particular author. This only works in Google Groups.
group | Looks for a group name. This only works in Google Groups.
insubject | Searches subject lines in posts. This only works in Google Groups.
msgid | Searches within a group for a message ID.


- `eg.: site:bbc.co.uk filetype:pdf` > finds all pdfs on BBC site

- BTW this is baad: intitle:index.of
