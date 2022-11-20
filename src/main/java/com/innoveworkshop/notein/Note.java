package com.innoveworkshop.notein;

import java.util.ArrayList;
import java.util.List;

import com.innoveworkshop.notein.data.NoteFormat;

/**
 * Abstraction of a note in a workspace.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */
public class Note {
	private String title;
	private NoteFormat format;
	private ArrayList<String> attributes;
	private String content;
	private String path;

	/**
	 * Creates a blank note object.
	 */
	public Note() {
		// Setup some defaults and ensure the object is invalid in the case
		// someone tries to save this.
		this.title = null;
		this.format = NoteFormat.PLAIN;
		this.attributes = new ArrayList<String>();
		this.content = "";
		this.path = null;
	}

	/**
	 * Creates a basic note object with the minimal requirements.
	 *
	 * @param title Note title.
	 * @param format Format of the content.
	 * @param path Path to the note relative to the workspace it's in.
	 */
	public Note(String title, NoteFormat format, String path) {
		this();
		this.title = title;
		this.format = format;
		this.path = path;
	}

	/**
	 * Gets the note title.
	 *
	 * @return Note title.
	 */
	public String getTitle() {
		return this.title;
	}

	/**
	 * Sets the note title.
	 *
	 * @param title New note title.
	 */
	public void setTitle(String title) {
		this.title = title;
	}

	/**
	 * Gets the note format that the content is using.
	 *
	 * @return Note content format.
	 */
	public NoteFormat getFormat() {
		return this.format;
	}

	/**
	 * Sets the note format that the content is using.
	 *
	 * @param format New note content format.
	 */
	public void setFormat(NoteFormat format) {
		this.format = format;
	}

	/**
	 * Gets the note attributes.
	 *
	 * @return Note attributes.
	 */
	public List<String> getAttributes() {
		return this.attributes;
	}

	/**
	 * Sets the note attributes.
	 *
	 * @param attributes New note attributes.
	 */
	public void setAttributes(List<String> attributes) {
		this.attributes = new ArrayList<String>(attributes);
	}

	/**
	 * Gets the note content.
	 *
	 * @return Note content.
	 */
	public String getContent() {
		return this.content;
	}

	/**
	 * Sets the note content.
	 *
	 * @param content New note content.
	 */
	public void setContent(String content) {
		this.content = content;
	}

	/**
	 * Gets the note path relative to the workspace it's in.
	 *
	 * @return Note path.
	 */
	public String getPath() {
		return this.path;
	}

	/**
	 * Sets the note path relative to the workspace it's in.
	 *
	 * @param path New note path.
	 */
	public void setPath(String path) {
		this.path = path;
	}

	@Override
	public String toString() {
		return this.title + "\n\n" + this.content;
	}
}
