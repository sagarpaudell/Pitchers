#ifndef DB_MANNAGER_H
#define DB_MANNAGER_H

#include <QSqlDatabase>
#include<QList>

class DbManager
{
public:
    DbManager();
    DbManager(const QString& path);

    /**
     * @brief Destructor
     *
     * Close the db connection
     */
    ~DbManager();
     QList<QList<QVariant>> getAllmostrated();
     QList<QList<QVariant>> getAllnepali();
     QList<QList<QVariant>> getAlldrama();
     QList<QList<QVariant>> getAllsouthindian();
     QList<QList<QVariant>> getAllhindi();
     QList<QList<QVariant>> getAllcrime();
     QList<QList<QVariant>> getAllhistory();
     QList<QList<QVariant>> getAllaction();
     QList<QList<QVariant>> getAllromance();
     QList<QList<QVariant>> getAlldocumentary();
     QList<QVariant> getmovies(QString name);
     QList<QString> getUserInfo(const QString& uname);
     QStringList getmoviesforsearch();
     QList<QVariant> display_search_details(const QString temp);
     bool isOpen() const;

    /**
     * @brief Creates a new 'user' table if it doesn't already exist
     * @return true - 'user' table created successfully, false - table not created
     */
    bool createTable();

    /**
     * @brief Add user data to db
     * @param email - email of user to add. email is unique
     * @param password - password of user to add
     * @param fname
     * @param lname
     * @param addr
     * @param phn
     * @return true - person added successfully, false - person not added
     */
    bool addUser(const QString& username,const QString& password,const QString& firstname,const QString& lastname,const QString& email,const QString& sex);

    /**
     * @brief Remove users data from db
     * @param email - email of user to remove.
     * @return true - user removed successfully, false - user not removed
     */
    bool removeUser(const QString& name);



    /**
     *@brief Check if the email is already taken
     */
    bool usernameExists(const QString& username);


    void printAllUsers() const;

    /**
     * @brief Remove all users username from db
     * @return true - all users removed successfully, false - not removed
     */
    bool removeAllUsers();


    /**
     * @brief Authenticate the users via username and password
     * @return db_primary_key - , 0 - log in failed
     */
    bool userAuth(const QString& name, const QString& pass) const;

    /**
     * @brief Get all the user data from the database
     * @return Returns list of strings
     */
    QList<QString> getUserInfo(const QString& email)const;

    /**
     * @brief Get all the email/id of the registerd users from database
     * @return Returns list of strings
     */
    QList<QString> getAllUsers();

private:
    QSqlDatabase db;
};
void getusernationality(QString nationality);
QString give();
#endif // DB_MANNAGER_H
