
Agenda:
- Purposes of a dameon
- Functionality
	- Support nesting
	- Document based
		- Each document has a set structure'



Notes:
Nosql: No relations
- Can scale vertically and horizontally
- Each item stands on its own
- Can partition db

Mongodb:
- Store data in json like documents
- Stored in collections
	- self contained
	- collections have a unique id
- Schema's are optional

Database contains collections
Documents (key value) organized into collections
Collection:
Group pf documents that share a similar purpose / entity
i.e) user collection will have have documents containing use info
Each collection goes into it's own Directory

//create user worksIndexes help to improve lookup (id field / email)

File structure
- Two methods:
	- Store documents into separate files (unique hash)
	- Store all documents relating to a collection into a single file


https://www.mongodb.com/resources/basics/databases/document-databases

Communications over http or gimApi 

Database
Collections
Documents (flexible)



![[Pasted image 20250304193055.png]]


# Request Types

//Use this section to define accepted Payload formats (Current one's are examples, feel free to add more)

// ------Possible Requests------

action: login,

payload: {

username: string,

password: string

} //Reponse: status = 200 if successful, status 400 if not with a message

  

action: register,

payload: {

username: string,

password: string, // Create, Read, Update, Delete

email: string

}//Reponse: status = 200 if successful, status 400 if not with a message

  

action: getAPIkey,

payload: {

username: string,

password: string

} //Reponse: status = 200 if successful, api key on message with expiry date // only one at a time

  

action: revokeAPIkey,

payload: {

username: string,

password: string,

apiKey: string

} //Reponse: status = 200 if successful, api key on message with expiry date // only one at a time

  

action: getPublicDatabases,

payload: {

limit: number,

offset: number

} //Reponse: status = 200 if successful, api key on message with expiry date // only one at a time

//Reponds with list of public databases

  

action: getDatabases,

payload: {

limit: number,

offset: number

} //Reponds with list of owned and shared private databases

  

action: createDatabase,

payload: {

apiKey: string,

dbName: string //

}///Reponse: status = 200 if successful, status 400 if not with a message

  
  

action: deleteDatabase,

apiKey: {

APIkey: string,

dbID: string //

}///Reponse: status = 200 if successful, status 400 if not with a message

  

action: loadDatabase,

payload: {

apiKey: string,

dbID: string //

}//Reponse: status = 200 if successful, status 400 if not with a message

//Once a database is loaded no other user can access it untill it's unloaded (probably by timeout, might need to reload on the rest api side)

action: unloadDatabase,

payload: {

apiKey: string,

dbID: string //

}//Reponse: status = 200 if successful, status 400 if not with a message

  

action: manageDatabase,

payload: { //some are optional depending on context, will manage the current loaded DB

apiKey: string,

DataBaseID: string,

operation: string, // Create, Read, Update, Delete, Add

collectionName: string // name of collection (table) to be updated / read / deleted

documentID: string // id of document (data entry) to be updated / read / deleted || Optional

documentData: {}//data to be added/updated || Optional

  

//Create -> Adds a new collection to database (basically a table)

//Add -> Adds documents (data) to a collection

//Read -> Adds a new collection to database (basically a table)

//Update -> Updates a document in a collection

//Delete -> deletes a document or delete a collection if documentID is null

  

action: shareDatabase,

payload: {

apiKey: string,

userID: string //user we want to share with

}//Reponse: status = 200 if successful, status 400 if not with a message

  

action: unshareDatabase,

payload: {

apiKey: string,

userID: string //user we want to share with

}//Reponse: status = 200 if successful, status 400 if not with a message

  

}
