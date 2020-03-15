using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace JobSearchLogConsole1
{
    public enum Activitytype
    {
        EMPLOYER_CONTACT,
        WORKSOURCE_ACTIVITY
    }
    public enum ContactMethod
    {
        ONLINE_EMAIL,
        FAX,
        IN_PERSON,
        MAIL,
        KIOSK,
        TELEPHONE,
        OTHER
    }
    public class ContactType
    {
        // this will hold one contact method
        public ContactMethod Method { get; set; }

        // contact methods as boolian (in case there are > 1 methods used
        public bool OnlineOrEmail { get; set; }
        public bool Fax { get; set; }
        public bool InPerson { get; set; }
        public bool Mail { get; set; }
        public bool Kiosk { get; set; }
        public bool Telephone { get; set; }
        public bool Other { get; set; }
        // enter description of how the contact was made
        public string OtherDescribe { get; set; }
    }
    public class WorksourceActivityInfo
    {
        public string Describe { get; set; }
    }
    public class EmployerContactAttributes
    {
        public bool ApplicationOrResume { get; set; }
        public bool Interview { get; set; }
        public bool Inquiry { get; set; }
        public string Position { get; set; }
        public ContactType HowContacted;
        public WorksourceActivityInfo WorksourceActivity { get; set; }

    }
    public class EmployerContactData
    {
        public string Name { get; set; }
        public string Telephone { get; set; }
        public string FaxNumber { get; set; }
        public string Address { get; set; }
        public string City { get; set; }
        public string State { get; set; }
        // name or position of person contacted (in-person contact)
        public string PersonContactedOrPosition { get; set; }

        // these are related to non-in-person contact
        public string Email { get; set; }
        public string WebSite { get; set; }
        public string JobReferenceNumber { get; set; }
    }

    public class JobSearchActivity
    {
        public DateTime contactDate;
        public Activitytype ActivityType { get; set; }
        public bool EmployerContact { get; set; }
        public bool WorksourceActivity { get; set; }

        public EmployerContactData employerContactData;

        


    }
    public class TestJobSearchActivities
    {

    }
    public class JobSearchActivityCollection
    {
        public DateTime weekEnding;
        // TODO: ADD COLLECTION OF CONTACTS
    }
    class Program
    {
        static void Main(string[] args)
        {
            string input = "true";
            bool testbool = bool.Parse(input);

            Console.WriteLine("bool test parse input[{0}] result[{1}]", input, testbool.ToString());
        }
    }
}
