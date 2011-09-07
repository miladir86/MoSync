/*
 * Event.h
 *
 *  Created on: Jul 2, 2011
 *      Author: gabi
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "FacebookObject.h"
#include "Utilities.h"

/**
 * Implements an Event Facebook object.
 * See: http://developers.facebook.com/docs/reference/api/event/
 */
class Event: public FacebookObject
{
public:
	/**
	 * Setter/getter for the "owner" field of an Event object.
	 * @param owner - the profile that created the event.
	 */
	void setOwner(const IdNamePair &owner);
	const IdNamePair &getOwner() const;

	/**
	 * Setter/getter for the "name" field of an Event object.
	 * @param name - the event title
	 */
	void setName(const MAUtil::String &name);
	const MAUtil::String &getName() const;

	/**
	 * Setter/getter for the "description" field of an Event object.
	 * @param name - the description of the event.
	 */
	void setDescription(const MAUtil::String &descr);
	const MAUtil::String &getDescription() const;

	/**
	 * Setter/getter for the "start_time" field of an Event object.
	 * @param startTime - the start time of the event
	 */
	void setStartTime(const MAUtil::String &startTime);
	const MAUtil::String &getStartTime() const;

	/**
	 * Setter/getter for the "start_time" field of an Event object.
	 * @param endTime - the end time of the event
	 */
	void setEndTime(const MAUtil::String &endTime);
	const MAUtil::String &getEndTime() const;

	/**
	 * Setter/getter for the "location" field of an Event object.
	 * @param location - the location for this event
	 */
	void setLocation(const MAUtil::String &location);
	const MAUtil::String &getLocation() const;

	/**
	 * Setter/getter for the "venue" field of an Event object.
	 * @param venue - the location for this event. A venue object contains:
	 * street, city, state, zip, country, latitude, and longitude fields.
	 */
	void setVenue(const Venue &venue);
	const Venue &getVenue() const;

	/**
	 * Setter/getter for the "privacy" field of an Event object.
	 * @param privacy - the visibility of this event. Can have the following values: "OPEN", "CLOSED", or "SECRET".
	 */
	void setPrivacy(const MAUtil::String &privacy);
	const MAUtil::String &getPrivacy() const;

private:
	IdNamePair		mOwner;
	MAUtil::String 	mName;
	MAUtil::String  mDescription;
	MAUtil::String  mStartTime;
	MAUtil::String  mEndTime;
	MAUtil::String  mLocation;
	Venue			mVenue;
	MAUtil::String 	mPrivacy;
};

#endif /* EVENT_H_ */
