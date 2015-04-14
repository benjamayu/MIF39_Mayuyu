// ------------------------------------------------------------------------------
//  <autogenerated>
//      This code was generated by a tool.
//      Mono Runtime Version: 4.0.30319.1
// 
//      Changes to this file may cause incorrect behavior and will be lost if 
//      the code is regenerated.
//  </autogenerated>
// ------------------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.Runtime.Serialization;
using FuzzyLogic;

namespace FuzzyLogic
{
	[DataContract]
	public class RuleBlock : NamedObject
	{
		[DataMember(Name="Conclusions")]
		public List < int > ConclusionsByID { get; set; }
		[IgnoreDataMember]
		public IndirectObjectList<Rule> Conclusions {
			get { 
				if (ConclusionsByID == null)
					ConclusionsByID = new List < int > ();
				return new IndirectObjectList<Rule> (this.Referee, ConclusionsByID);
			}
		}
		//
		public Rule this [int index]
		{
			get {
				if ((index >= 0) && (index < ConclusionsByID.Count))
					return (Rule) Referee.internals [ConclusionsByID [index]];
				else throw new IndexOutOfRangeException();
			}
		}
		public int Count {
			get { return ConclusionsByID.Count; }
		}
		public void Add (Rule r)
		{
			if (ConclusionsByID == null)
				ConclusionsByID = new List<int> ();
			ConclusionsByID.Add (r);
		}
	}
}
