﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System.Xml.Serialization;

// 
// This source code was auto-generated by xsd, Version=4.6.1055.0.
// 


/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
[System.Xml.Serialization.XmlRootAttribute("weekly-job-search-log", Namespace="", IsNullable=false)]
public partial class weeklyjobsearchlog {
    
    private string weekendingField;
    
    private weeklyjobsearchlogActivity[] activityField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("week-ending", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string weekending {
        get {
            return this.weekendingField;
        }
        set {
            this.weekendingField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("activity", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public weeklyjobsearchlogActivity[] activity {
        get {
            return this.activityField;
        }
        set {
            this.activityField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
public partial class weeklyjobsearchlogActivity {
    
    private string dateField;
    
    private string typeField;
    
    private string employercontactField;
    
    private string worksourceactivityField;
    
    private weeklyjobsearchlogActivityActivitydetails[] activitydetailsField;
    
    private weeklyjobsearchlogActivityContactinfo[] contactinfoField;
    
    private weeklyjobsearchlogActivityContactindirect[] contactindirectField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string date {
        get {
            return this.dateField;
        }
        set {
            this.dateField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string type {
        get {
            return this.typeField;
        }
        set {
            this.typeField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("employer-contact", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string employercontact {
        get {
            return this.employercontactField;
        }
        set {
            this.employercontactField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("worksource-activity", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string worksourceactivity {
        get {
            return this.worksourceactivityField;
        }
        set {
            this.worksourceactivityField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("activity-details", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public weeklyjobsearchlogActivityActivitydetails[] activitydetails {
        get {
            return this.activitydetailsField;
        }
        set {
            this.activitydetailsField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("contact-info", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public weeklyjobsearchlogActivityContactinfo[] contactinfo {
        get {
            return this.contactinfoField;
        }
        set {
            this.contactinfoField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("contact-indirect", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public weeklyjobsearchlogActivityContactindirect[] contactindirect {
        get {
            return this.contactindirectField;
        }
        set {
            this.contactindirectField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
public partial class weeklyjobsearchlogActivityActivitydetails {
    
    private weeklyjobsearchlogActivityActivitydetailsEmployer[] employerField;
    
    private weeklyjobsearchlogActivityActivitydetailsWorksource[] worksourceField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("employer", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public weeklyjobsearchlogActivityActivitydetailsEmployer[] employer {
        get {
            return this.employerField;
        }
        set {
            this.employerField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("worksource", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public weeklyjobsearchlogActivityActivitydetailsWorksource[] worksource {
        get {
            return this.worksourceField;
        }
        set {
            this.worksourceField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
public partial class weeklyjobsearchlogActivityActivitydetailsEmployer {
    
    private string typeField;
    
    private string applicationorresumeField;
    
    private string interviewField;
    
    private string inquiryField;
    
    private string positionField;
    
    private weeklyjobsearchlogActivityActivitydetailsEmployerContactmechanism[] contactmechanismField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string type {
        get {
            return this.typeField;
        }
        set {
            this.typeField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("application-or-resume", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string applicationorresume {
        get {
            return this.applicationorresumeField;
        }
        set {
            this.applicationorresumeField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string interview {
        get {
            return this.interviewField;
        }
        set {
            this.interviewField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string inquiry {
        get {
            return this.inquiryField;
        }
        set {
            this.inquiryField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string position {
        get {
            return this.positionField;
        }
        set {
            this.positionField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("contact-mechanism", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public weeklyjobsearchlogActivityActivitydetailsEmployerContactmechanism[] contactmechanism {
        get {
            return this.contactmechanismField;
        }
        set {
            this.contactmechanismField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
public partial class weeklyjobsearchlogActivityActivitydetailsEmployerContactmechanism {
    
    private string typeField;
    
    private string onlineoremailField;
    
    private string faxField;
    
    private string inpersonField;
    
    private string mailField;
    
    private string kioskField;
    
    private string telephoneField;
    
    private string otherField;
    
    private string otherdescriptionField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string type {
        get {
            return this.typeField;
        }
        set {
            this.typeField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("online-or-email", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string onlineoremail {
        get {
            return this.onlineoremailField;
        }
        set {
            this.onlineoremailField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string fax {
        get {
            return this.faxField;
        }
        set {
            this.faxField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("in-person", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string inperson {
        get {
            return this.inpersonField;
        }
        set {
            this.inpersonField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string mail {
        get {
            return this.mailField;
        }
        set {
            this.mailField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string kiosk {
        get {
            return this.kioskField;
        }
        set {
            this.kioskField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string telephone {
        get {
            return this.telephoneField;
        }
        set {
            this.telephoneField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string other {
        get {
            return this.otherField;
        }
        set {
            this.otherField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("other-description", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string otherdescription {
        get {
            return this.otherdescriptionField;
        }
        set {
            this.otherdescriptionField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
public partial class weeklyjobsearchlogActivityActivitydetailsWorksource {
    
    private string descriptionField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string description {
        get {
            return this.descriptionField;
        }
        set {
            this.descriptionField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
public partial class weeklyjobsearchlogActivityContactinfo {
    
    private string nameField;
    
    private string telephoneField;
    
    private string faxField;
    
    private string addressField;
    
    private string cityField;
    
    private string stateField;
    
    private string zipField;
    
    private string websiteField;
    
    private string positionField;
    
    private weeklyjobsearchlogActivityContactinfoContactperson[] contactpersonField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string name {
        get {
            return this.nameField;
        }
        set {
            this.nameField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string telephone {
        get {
            return this.telephoneField;
        }
        set {
            this.telephoneField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string fax {
        get {
            return this.faxField;
        }
        set {
            this.faxField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string address {
        get {
            return this.addressField;
        }
        set {
            this.addressField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string city {
        get {
            return this.cityField;
        }
        set {
            this.cityField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string state {
        get {
            return this.stateField;
        }
        set {
            this.stateField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string zip {
        get {
            return this.zipField;
        }
        set {
            this.zipField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("web-site", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string website {
        get {
            return this.websiteField;
        }
        set {
            this.websiteField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string position {
        get {
            return this.positionField;
        }
        set {
            this.positionField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("contact-person", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public weeklyjobsearchlogActivityContactinfoContactperson[] contactperson {
        get {
            return this.contactpersonField;
        }
        set {
            this.contactpersonField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
public partial class weeklyjobsearchlogActivityContactinfoContactperson {
    
    private string nameField;
    
    private string positionField;
    
    private string emailField;
    
    private string phoneField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string name {
        get {
            return this.nameField;
        }
        set {
            this.nameField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string position {
        get {
            return this.positionField;
        }
        set {
            this.positionField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string email {
        get {
            return this.emailField;
        }
        set {
            this.emailField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string phone {
        get {
            return this.phoneField;
        }
        set {
            this.phoneField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
public partial class weeklyjobsearchlogActivityContactindirect {
    
    private string faxField;
    
    private string emailField;
    
    private string jobreferencenumberField;
    
    private weeklyjobsearchlogActivityContactindirectNewspaper[] newspaperField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string fax {
        get {
            return this.faxField;
        }
        set {
            this.faxField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string email {
        get {
            return this.emailField;
        }
        set {
            this.emailField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("job-reference-number", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string jobreferencenumber {
        get {
            return this.jobreferencenumberField;
        }
        set {
            this.jobreferencenumberField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("newspaper", Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public weeklyjobsearchlogActivityContactindirectNewspaper[] newspaper {
        get {
            return this.newspaperField;
        }
        set {
            this.newspaperField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
public partial class weeklyjobsearchlogActivityContactindirectNewspaper {
    
    private string nameField;
    
    private string dateField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string name {
        get {
            return this.nameField;
        }
        set {
            this.nameField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute(Form=System.Xml.Schema.XmlSchemaForm.Unqualified)]
    public string date {
        get {
            return this.dateField;
        }
        set {
            this.dateField = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "4.6.1055.0")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true)]
[System.Xml.Serialization.XmlRootAttribute(Namespace="", IsNullable=false)]
public partial class NewDataSet {
    
    private weeklyjobsearchlog[] itemsField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("weekly-job-search-log")]
    public weeklyjobsearchlog[] Items {
        get {
            return this.itemsField;
        }
        set {
            this.itemsField = value;
        }
    }
}
